//
//  ViewController.m
//  MorphiiSampleObjc
//
//  Created by Chris K on 9/25/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import "ViewController.h"
@interface ViewController ()
@property (strong, nonatomic) BasicView* basicView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _morphiiArray = [[NSArray alloc] init];
}

- (void)viewDidAppear:(BOOL)animated
{
    MorphiiService* service = [MorphiiService sharedInstance];
    service.serviceDelegate = self;
    //Setting API Key Required. You may set with or Without a subaccount
//    [service setAPIKey:@"pJEOKdYSqd4cUxJNbuX3G294G4GuRdT2ak7D5OMu" accountId:@"17253015"];
    [service setAPIKey:@"pJEOKdYSqd4cUxJNbuX3G294G4GuRdT2ak7D5OMu" accountId:@"17253015" withSubAccountID:@"test-sub-id" andSubAccountName:@"test-sub-name"];
    
    // Create the Morphii configuration
    MorphiiConfiguration* morphiiConfig = [[MorphiiConfiguration alloc] init:YES];
    [morphiiConfig addWithID:@"6439955463778914304" name: nil weight: 0];
    
    [self addNewBasicView:morphiiConfig];
    
    MorphiiConfiguration* morphiiConfig2 = [[MorphiiConfiguration alloc] init:YES];
    [morphiiConfig2 addWithID:@"6387684990323101696" name: nil weight: 1];
    [morphiiConfig2 addWithID:@"6387687516724666368" name: nil weight: 2];
    [morphiiConfig2 addWithID:@"6387687738608865280" name: nil weight: 3];
    [morphiiConfig2 addWithID:@"6387686352809422848" name: nil weight: 4];
    [morphiiConfig2 addWithID:@"6387687144609767424" name: nil weight: 5];
    [morphiiConfig2 addWithID:@"6387687069345202176" name: nil weight: 6];
    [morphiiConfig2 addWithID:@"6387687641635434496" name: nil weight: 7];

    /***********METHODS WITHOUT DELEGATES***********/
    
    /*** Uncomment to Present a scrollView of morphiis with no delegate methods.*/
    UIView * selectionView = [service addSelectionViewWithIntensity:1.0 config:morphiiConfig2 delegate:self];
    [[self selectionView] addSubview:selectionView];
    
    /***********METHODS WITH DELEGATES***********/
    
    // Uncomment to collect morphiis as an array, Morphii Objects have an Image Property For Display
    // [service getMorphiisAsArray:morphiiConfig2 withSize:115 intensity:1.0];
    
    // Uncomment to Present a scrollView of morphiis with delegate methods.
    // [service addSelectionViewWithResponse:1.0 config:morphiiConfig2 delegate:self];
}

/************************DELEGATE METHODS*********************************/
- (void) morphiiArrayReceived:(NSArray *)morphiis{
    
    _collectionView.dataSource = self;
    _collectionView.delegate = self;
    
    _morphiiArray = [NSArray arrayWithArray:morphiis];
    [_collectionView reloadData];
}

- (void) morphiiSelectionViewAdded:(MorphiiSelectionView *)morphiiSelectionView
{
    [[self selectionView] addSubview:morphiiSelectionView];
}

- (void) morphiiBasicViewAdded:(BasicView *)basicView
{
    self.basicView = basicView;
    [[self containerView] addSubview:self.basicView];
}


- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    UICollectionViewCell *myCell = (UICollectionViewCell *)[collectionView dequeueReusableCellWithReuseIdentifier:@"MyCustomCell" forIndexPath:indexPath];
    
    Morphii * md = [_morphiiArray objectAtIndex:indexPath.item];
    
    UIImageView *recipeImageView = (UIImageView *)[myCell viewWithTag:100];
    recipeImageView.image = md.morphiiPng;
    myCell.backgroundView = recipeImageView;
    
    return myCell;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [_morphiiArray count];
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    //Diplay morphii Information or create a morphii config and pass to basic view
    Morphii * md = [_morphiiArray objectAtIndex:indexPath.item];
    NSLog(@"Chosen Morphii name: %@",md.name);
    NSLog(@"Chosen Morphii displayName: %@",md.displayName);

    // Create the Morphii configuration
    MorphiiConfiguration* morphiiConfig = [[MorphiiConfiguration alloc] init:YES];
    [morphiiConfig addWithID:md.id name:md.displayName weight: 0];
    
    [self addNewBasicView:morphiiConfig];
}

- (void)selectedMorphii:(MorphiiConfiguration *)morphiiConfiguration
{
    //Can use morphiiConfiguration to open a Basic View
    if([morphiiConfiguration.morphiiDetails count] > 0){
        NSLog(@"Chosen Morphii displayName: %@",morphiiConfiguration.morphiiDetails[0].displayName);
        NSLog(@"Chosen Morphii name: %@",morphiiConfiguration.morphiiDetails[0].name);

        [self addNewBasicView:morphiiConfiguration];
    }
}

- (void) addNewBasicView:(MorphiiConfiguration*)morphiiConfiguration
{
    for(UIView * subview in self.containerView.subviews) {
        [subview removeFromSuperview];
    }
    
    MorphiiService * service = [MorphiiService sharedInstance];
    //Create Project
    Project* project = [[Project alloc] init:@"my-project-id" withDescription:@"My Project Description"];
    service.project = project;
    
    // Create Target
    NSDictionary* metadata = @{ @"key1" : @"value-1", @"key2" : @"value-2" };
    Target* target = [[Target alloc] initWithID:@"target-id-1" withType:@"question" andData:metadata];
    
    // Create User
    NSDictionary* properties = @{ @"email": @"user@mailinator.com" , @"key2" : @"value-2" , @"key3" : @"value-3" };
    User * user = [[User alloc] initWithID:@"user-id" withType:@"external" andProperties:properties];
    
    // Options configuration. If Options not set, intensity will default to 0.50
    Options* options = [[Options alloc] init:@"test" withIntensity:0.20];
    
    // Comment configuration
    Comment* comment = [[Comment alloc] init:YES isRequired:NO withMaxLength:100 label:@"Post" andHintText:@"Post Here"];
    
    // Application configuration
    ApplicationInformation* appInfo = [[ApplicationInformation alloc] initWithName:@"Test App" description:@"Test App Desc" version:@"1.0" andProperties:nil];
    
    // Create the BasicViewConfiguration
    self.config = [[BasicViewConfiguration alloc] init];
    self.config.morphiiConfig = morphiiConfiguration;
    self.config.target = target;
    self.config.project = project;
    self.config.comment = comment;
    self.config.options = options;
    self.config.user = user;
    self.config.application = appInfo;
    self.config.showSlider = NO; //Change to YES if you'd like to see the slider horizontally
    self.config.showSliderVertical = NO; //Change both showSlider and showSliderVertical to YES if you'd like to see the slider vertically.
    
    /***********METHODS WITHOUT DELEGATES***********/
    
    // Uncomment to Present a basicView for a morphii to adjust intensity with no delegate methods.
    // self.basicView = [service addWithContainerView:[self containerView] config:self.config delegate:self];
    // [[self containerView] addSubview:self.basicView];
    
    /***********METHODS WITH DELEGATES***********/

    // Uncomment to Present a basicView for a morphii to adjust intensity with delegate methods.
     [service addBasicViewWithResponse:[self containerView] config:self.config delegate:self];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)commentChange:(NSString *)type commentRequiredValid:(BOOL)commentRequiredValid view:(BasicViewObject *)view
{
    NSLog(@"Change Type %@",type);
}

- (IBAction)submitAction:(id)sender {
    [[MorphiiService sharedInstance] submit:^(NSArray *results) { // change results name to records
        NSLog(@"called submit");
        for (ReactionResultRecord* record in results) {
            NSLog(@"Results Record");
            NSLog(@"================================================");
            NSLog(@"targetId: %@", record.targetId);
            NSLog(@"viewId: %@", record.viewId);
            
            if (!record.isSubmitted) {
                // There was an error.
                NSLog(@"error code: %@", record.error.code);
                NSLog(@"error message: %@", record.error.message);
            }
            else {
                NSLog(@"reactionId: %@", record.reactionId);
                
                if (record.morphii != nil) {
                    NSLog(@"morphii-id: %@", record.morphii.id);
                    NSLog(@"morphii-name: %@", record.morphii.name);
                    NSLog(@"morphii-displayName: %@", record.morphii.displayName);
                    NSLog(@"morphii-partName: %@", record.morphii.partName);
                    NSLog(@"morphii-intensity:  %f", record.morphii.intensity);
                    NSLog(@"morphii-weight:  %d", record.morphii.weight);
                }
                else {
                    NSLog(@"No morphii details provided.");
                }
                
                if (record.comment != nil) {
                    NSLog(@"comment-text: %@", record.comment.text);
                    NSLog(@"comment-locale: %@", record.comment.locale);
                }
                else {
                    NSLog(@"No comment field");
                }
            }
            
            NSLog(@"================================================");
            NSLog(@"================================================");
        }
    }];
}

- (IBAction)resetAction:(id)sender {
    [self.basicView resetWithComment:YES];
}
@end
