//
//  ViewController.m
//  MorphiiObjCRuntTest
//

#import "ViewController.h"
#import <MorphiiSDK/MorphiiSDK.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIImageView* imageView;
@property (strong, nonatomic) BasicView* basicView;

@end

@implementation ViewController

- (void)viewDidLoad {
   [super viewDidLoad];
   // Do any additional setup after loading the view, typically from a nib.
   
   MorphiiService* service = [MorphiiService sharedInstance];
   [service authenticateWithUsername:@"<user_name>" password:@"<user_password>" accountId:@"<account_id>" completion:^(AuthenticationResults * _Nonnull results) {
      if (results.isAuthenticated) {
          // Create Project
          Project* project = [[Project alloc] initWithId:@"my-project-id" description:@"My Project Description"];
          service.project = project;
          
          // Create Target
          NSDictionary* metadata = @{ @"value-1" : @"key1", @"value-2" : @"key2" };
          Target* target = [[Target alloc] initWithId:@"target-id-1" type:@"question" metadata:metadata];

          // Create User
          NSDictionary* properties = @{ @"user@mailinator.com" : @"email", @"value-2" : @"key2", @"value-3" : @"key3" };
          User* user = [[User alloc] initWithId:@"user-id" type:@"external" properties: properties];

          // Options configuration
          Options* options = [[Options alloc] initWithStage:@"test" initialIntensity:0.5];

          // Comment configuration
          Comment* comment = [[Comment alloc] initWithShow:NO required:NO maxLength:100 label:@"Post" hintText:@"Post Here"];

          // Create the Morphii configuration
          MorphiiConfiguration* morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
          [morphiiConfig addWithId:@"6202185104333209600" name:nil weight:1];
         
          // Create the BasicViewConfiguration
          BasicViewConfiguration* config = [[BasicViewConfiguration alloc] initWithMorphiiConfig:morphiiConfig target:target project:project comment:comment options:options user:user];
          _basicView = [service addWithContainerView:[self containerView] config:config delegate:nil];
          [[self containerView] addSubview:_basicView];
      }
      else {
          NSLog(@"Authentication failed");
          NSLog(@"error code: %@", results.error.code);
          NSLog(@"error message: %@", results.error.message);
      }
   }];
}
- (IBAction)submitButtonPressed:(UIButton *)sender {
   [[MorphiiService sharedInstance] submitWithCompletion:^(NSArray<ReactionResultRecord *> * _Nonnull records) {
      for (ReactionResultRecord* record in records) {
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
                  NSLog(@"morphii-intensity:  %f", record.morphii.intensity);
                  NSLog(@"morphii-weight:  %ld", record.morphii.weight);
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
- (IBAction)getPngButtonPressed:(UIButton *)sender {
   UIImage* image = [_basicView pngWithSize:CGSizeMake(60, 60)];
   NSLog(@"PNG image: %@", image);
   [_imageView setImage: image];
}

- (IBAction)resetButtonPressed:(UIButton *)sender {
   [[MorphiiService sharedInstance] resetWithComment:YES];
}


- (void)didReceiveMemoryWarning {
   [super didReceiveMemoryWarning];
   // Dispose of any resources that can be recreated.
}


@end
