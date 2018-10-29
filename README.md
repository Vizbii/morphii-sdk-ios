![Morphii SDK](https://d24bblcmguio2o.cloudfront.net/content/images/logo-black-color@3x.png)

# Morphii SDK (version 2)

## What It Is
The Morphii SDK provides developers with the ability to add a morphii technology to iOS native apps. Morphii allows the user to manipulate the type and intensity of the emotion. There are several different morphiis to allow for a full range of possible emotions. The developer also has the option to include a comment section along with the morphii. The developer then can gather pertinent information from the user's interaction with the morphiis to use for analytical purposes. For more information see the [Morphii Site](http://morphii.com).

## How to Use It

### Requirements

- Xcode 8.+
- Minimum deployment target of 10.2


### Manual Project Setup
1. Create a new project in Xcode.
2. Include the MorphiiSDK.framework File in the top of the projects directory
3. Go to the projects target settings in Xcode
4. Add the MorphiiSDK.framework to the 'Embedded Binaries' list
5. Add the MorphiiSDK.framework to the 'Linked Frameworks and Libraries' list
6. Add import MorphiiSDK wherever you would like to utilize the SDK

### Project Settings
If building for a device there is a setting, 'GPU Frame Capture' that must be disabled in Xcode after the project has been created in order for the morphiis to run.
1. In Xcode, open Product from the toolbar
2. Navigate to Scheme then Edit Scheme
3. Open the Run Side Bar
4. Click to the 'Options' tab
5. Set GPU Frame Capture to disabled.


## Importing
The following are imports needed to use the Morphii SDK.

```swift
// Swift
import MorphiiSDK
```

```objective-c
// Objective-C
#import <MorphiiSDK/MorphiiSDK.h>
```


### <a name="morphiiservice"></a>MorphiiService
The MorphiiService class is the main class the developer will work with. This class holds methods for authentication, adding a MorphiiView, and submitting data to receive the Result Records, which contains the data of user inputs. All MorphiiService methods will be called from a sharedInstance object. Example:

When instantiating a MorphiiService object be sure to set the API Key and Account ID

```swift
// Swift
override func viewDidLoad() {
  super.viewDidLoad()
  // Do any additional setup after loading the view, typically from a nib.

  let service = MorphiiService.sharedInstance()  
}
```


```objective-c
// Objective-C
- (void)viewDidLoad {
  [super viewDidLoad];

  MorphiiService *service = [MorphiiService sharedInstance];
}
```

#### Set APIKey and AccountId*

`public func setAPIKey("inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb", accountId:"17744669")`

Or

`public func setAPIKey("inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb", accountId:"17744669", withSubAccountID: "test-sub-id", andSubAccountName: "test-sub-name")`


This method adds an API Key and account Id to the MorphiiService. The first method requires two parameters: a `APIKey` and an `AccountId` . Developers also have the option of attaching a sub account to the MorphiiService. This method requires four parameters: `APIKey` , `AccountId` , `SubAccountID` , and `SubAccountName`. Setting the API key and account Id  [Is Required](#isrequired) and allows the MorphiiService to complete necessary service calls.

```swift
// Swift
override func viewDidLoad() {
super.viewDidLoad()
// Do any additional setup after loading the view, typically from a nib.

let service = MorphiiService.sharedInstance()

service?.setAPIKey("inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb", accountId: "17744669")
//Or
service?.setAPIKey("inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb", accountId: "17744669", withSubAccountID: "test-sub-id", andSubAccountName: "test-sub-name")
}
```


```objective-c
// Objective-C
- (void)viewDidLoad {
    [super viewDidLoad];

    MorphiiService *service = [MorphiiService sharedInstance];

    [service setAPIKey:@"inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb" accountId:@"17744669"];
    //Or
    [service setAPIKey:@"inoawqT0Qc85MgynAGbKsromLgMXyt028Ynlj3vb" accountId:@"17744669" withSubAccountID:@"test-sub-id" andSubAccountName:@"test-sub-name"];
}
```

#### MorphiiServiceDelegate

The `MorphiiServiceDelegate` provides developers with feedback from the Morphii framework. It consists of three methods that return different various data and views.  These methods are linked to the [MorphiiService] methods `addBasicView(withResponse:...`, `addSelectionView(withResponse:...` and `getMorphiisAsArray...`. The developer must first have their class subscribe to be a delegate or extension of the MorphiiServiceDelegate (called  `serviceDelegate`), this allows the class to access the methods linked to the methods mentioned previously. Once a class has been defined as a delegate or extension of the `MorphiiServiceDelegate`, the user can use the above methods and responses for these methods will be returned in delegate/response methods. These delegate/response methods are: `morphiiBasicViewAdded(_ basicView: BasicView)`, `morphiiSelectionViewAdded(_ morphiiSelectionView: MorphiiSelectionView)`, and `morphiiArrayReceived(_ morphiis: [Any]!)`.  Having these delegate methods available to the developer allows her/him to do things like display a progress loading bar in between calling for a Morphii and showing it on the screen. These delegate methods are shown below. Again, to use these methods in a class the developer must first define that class as the MorphiiServiceDelegate then implement the necessary delegate methods inside that class. Ex.

```swift
// Swift
override func viewDidLoad() {
super.viewDidLoad()
// Do any additional setup after loading the view, typically from a nib.

let service = MorphiiService.sharedInstance()
service.serviceDelegate = self
}

extension ViewController:MorphiiServiceDelegate {
    func morphiiSelectionViewAdded(_ morphiiSelectionView: MorphiiSelectionView) { // A Morphii selectionView is returned
        self.containerView.addSubview(morphiiSelectionView)
        print("Selection View Added")
    }   
    func morphiiBasicViewAdded(_ basicView: BasicView) { // A Morphii BasicView is returned
        self.basicView = basicView
        containerView2.addSubview(self.basicView!)
        print("Basic View Added")
    }
    func morphiiArrayReceived(_ morphiis: [Any]!) { // An array of Morphii objects is returned
        print(morphiis as! [Morphii])
    }
}
```


```objective-c
// Objective-C
- (void)viewDidLoad {
    [super viewDidLoad];
    MorphiiService *service = [MorphiiService sharedInstance];
    service.serviceDelegate = self;
}


//In Objective-C the developer must implement these methods individually.
- (void) morphiiSelectionViewAdded:(MorphiiSelectionView *)morphiiSelectionView  // A Morphii selectionView is returned
{
    [[self selectionView] addSubview:morphiiSelectionView];
}

- (void) morphiiBasicViewAdded:(BasicView *)basicView // A Morphii BasicView is returned
{
    self.basicView = basicView;
    [[self containerView] addSubview:self.basicView];
}
- (void) morphiiArrayReceived:(NSArray *)morphiis{ // An array of Morphii objects is returned

    _collectionView.dataSource = self;
    _collectionView.delegate = self;

    _morphiiArray = [NSArray arrayWithArray:morphiis];
    [_collectionView reloadData];
}

```


#### Add
`public func add(containerView:UIView, config:BasicViewConfiguration, delegate:BasicViewDelegate?) -> BasicView`

This method adds a [BasicView](#basicview) to the specified container layout. The method requires one parameter: a `basicViewConfiguration`. To create an instance of [BasicViewConfiguration](#basicviewconfiguration) you will need to create a number of supporting classes to pass into the configuration as parameters. Check the Supporting Classes section for more information. The `add` method will return a [BasicView](#basicview) if successful and `null` if there was an error.

```swift
// Swift
func createBasicView(containerView: UIView) -> BasicView {

  // Create Project
  let project = Project(id: "my-project-id", description: "My Project Description")

  // Create Target
  let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2"]
  let target = Target(id: "my-target-id", type: "question", metadata: metadata)

  // Options configuration
  let options = Options(stage: "live", initialIntensity: 0.5)

  // Comment configuration
  let comment = Comment(show: false, required: false, maxLength: 100, label: "Comment", hintText: "Enter comment")

  // Create User
  let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
  let user = User(id: "user-id", type: "external", properties: properties)

  // Morphii configuration.
  let morphiiConfig = MorphiiConfiguration(showName: true)
  morphiiConfig.add(id: "6202184382145363968", name: nil, weight: 1)

  // Create the BasicViewConfiguration and add to the service.
  let config = BasicViewConfiguration(morphiiConfig: morphiiConfig, target: target, project: project, comment: comment, options: options, user: user)

  let service = MorphiiService.sharedInstance()
  let basicView = service.add(containerView: containerView, config: config, delegate: self)
  return basicView
}
```

```objective-c
// Objective-C
-(BasicView*)createBasicView: (UIView *)container {

  // Project information
  Project *project = [[Project alloc] initWithId:@"my-project-id" description:@"My project description"];

  // Target info
  NSDictionary *metadata = @{@"value-1":@"key1", @"value-2":@"key2"};
  Target *target = [[Target alloc] initWithId:@"my-target-id" type:@"question" metadata:metadata];

  // Options info
  Options *options = [[Options alloc] initWithStage:@"live" initialIntensity:0.5];

  // Comment info
  Comment *comment = [[Comment alloc] initWithShow:NO required:NO maxLength:100 label:@"Comment" hintText:@"Enter comment"];

  // User data
  NSDictionary *properties = @{@"user.name@mailinator.com":@"email", @"value-2":@"key2", @"value-3":@"key3"};
  User *user = [[User alloc] initWithId:@"user-id" type:@"external" properties:properties];

  // Morphii information
  MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
  [morphiiConfig addWithId:@"6202184382145363968" name:nil weight:1];

  BasicViewConfiguration *config = [[BasicViewConfiguration alloc] initWithMorphiiConfig:morphiiConfig target:target project:project comment:comment options:options user:user];

  MorphiiService *service = [MorphiiService sharedInstance];    
  BasicView *basicView = [service addWithContainerView:container config:config delegate:nil];
  [container addSubview:basicView];
  return basicView;
}
```
#### Add BasicView With Delegate
`public func addBasicView(withResponse: containerView, config: config, delegate: MorphiiServiceDelegate)`

This method adds a [BasicView](#basicview) to the specified container layout with a callback . The method requires one parameter: a `basicViewConfiguration`. To create an instance of [BasicViewConfiguration](#basicviewconfiguration) you will need to create a number of supporting classes to pass into the configuration as parameters. Check the Supporting Classes section for more information. The `add` method will callback to the delegate method `func morphiiBasicViewAdded(_ basicView: BasicView)`.

This delegate method exists as part of the MorphiiServiceDelegate extension.

```swift
// Swift
func createBasicView(containerView: UIView) -> BasicView {

    // Create Project
    let project = Project(id: "my-project-id", description: "My Project Description")

    // Create Target
    let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2"]
    let target = Target(id: "my-target-id", type: "question", metadata: metadata)

    // Options configuration
    let options = Options(stage: "live", initialIntensity: 0.5)

    // Comment configuration
    let comment = Comment(show: false, required: false, maxLength: 100, label: "Comment", hintText: "Enter comment")

    // Create User
    let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
    let user = User(id: "user-id", type: "external", properties: properties)

    // Morphii configuration.
    let morphiiConfig = MorphiiConfiguration(showName: true)
    morphiiConfig.add(id: "6202184382145363968", name: nil, weight: 1)

    // Create the BasicViewConfiguration and add to the service.
    let config = BasicViewConfiguration(morphiiConfig: morphiiConfig, target: target, project: project, comment: comment, options: options, user: user)

    let service = MorphiiService.sharedInstance()
    service?.addBasicView(withResponse: containerView, config: config, delegate: self)// Adding basicView With Response. will return Basicview to morphiiBasicViewAdded Method
    //Developer can display loading screen here

}

extension ViewController:MorphiiServiceDelegate {

    func morphiiBasicViewAdded(_ basicView: BasicView) { // BasicView is Returned Here.
        //Developer can hide loading screen here
        self.basicView = basicView
        containerView2.addSubview(self.basicView!)
        print("Basic View Added")
    }
}

```

```objective-c
// Objective-C
-(BasicView*)createBasicView: (UIView *)container {

    // Project information
    Project *project = [[Project alloc] initWithId:@"my-project-id" description:@"My project description"];

    // Target info
    NSDictionary *metadata = @{@"value-1":@"key1", @"value-2":@"key2"};
    Target *target = [[Target alloc] initWithId:@"my-target-id" type:@"question" metadata:metadata];

    // Options info
    Options *options = [[Options alloc] initWithStage:@"live" initialIntensity:0.5];

    // Comment info
    Comment *comment = [[Comment alloc] initWithShow:NO required:NO maxLength:100 label:@"Comment" hintText:@"Enter comment"];

    // User data
    NSDictionary *properties = @{@"user.name@mailinator.com":@"email", @"value-2":@"key2", @"value-3":@"key3"};
    User *user = [[User alloc] initWithId:@"user-id" type:@"external" properties:properties];

    // Morphii information
    MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
    [morphiiConfig addWithId:@"6202184382145363968" name:nil weight:1];

    BasicViewConfiguration *config = [[BasicViewConfiguration alloc] initWithMorphiiConfig:morphiiConfig target:target project:project comment:comment options:options user:user];

    MorphiiService *service = [MorphiiService sharedInstance];    
    [service addBasicViewWithResponse:[self containerView] config:config delegate:self]; // Adding basicView With Response. will return Basicview to morphiiBasicViewAdded Method
}
- (void) morphiiBasicViewAdded:(BasicView *)basicView // BasicView is Returned Here.
{
    //Developer can hide loading screen here
    self.basicView = basicView;
    [[self containerView] addSubview:self.basicView];
}
```

#### <a name="addselectionview"></a>AddSelectionView
`public func addSelectionView (initialIntensity:Double, config:MorphiiConfiguration, delegate:MorphiiSelectionViewDelegate) -> MorphiiSelectionView?`

This method returns a [MorphiiSelectionView](#morphiiselectionview) object that can be added to your container layout just like a `SingleMorphiiView`. This method requires three parameters: `initialIntensity`, `MorphiiConfiguration`, and `MorphiiSelectionViewDelegate`. The `MorphiiConfiguration` is an instance of the [MorphiiConfiguration](#morphiiconfiguration) object that configures how the morphii will be displayed. The `initialIntensity` is a Double that determines the starting intensity for the rendered morphiis. The `MorphiiSelectionViewDelegate` returns the `MorphiiConfiguration` of the selected morphii that can be used to create a new `BasicViewConfiguration` that can be used to add a new `BasicView` to allow the user to manipulate and utilize the selected morphii.

```swift
// Swift
func createSelectionView() -> MorphiiSelectionView? {
  let service = MorphiiService.sharedInstance()

  let morphiiConfig = MorphiiConfiguration(showName: true)
  morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)
  morphiiConfig.add(id: "6202185110939238400", name: nil, weight: 2)
  return service.addSelectionView(initialIntensity: 1.0, config: morphiiConfig, delegate: self)
}
```

```objective-c
// Objective-C
-(MorphiiSelectionView*)createSelectionView {
  MorphiiService *service = [MorphiiService sharedInstance];   

  MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
  [morphiiConfig addWithId:@"6202185104333209600" name:nil weight:1];
  [morphiiConfig addWithId:@"6202185110939238400" name:nil weight:2];

  MorphiiSelectionView *morphiiSelectionView = [service addSelectionViewWithInitialIntensity:1.0 config:config delegate:nil];
  return morphiiSelectionView;
}
```

#### <a name="addselectionview"></a>AddSelectionView With Delegate

`public func addSelectionView(withResponse: 1.0, config: morphiiConfig, delegate: MorphiiServiceDelegate) `

This method retreives a morphiiSelectionView and returns it in a callback delegate method `morphiiSelectionViewAdded(_ morphiiSelectionView: MorphiiSelectionView)` . This method requires three parameters: `initialIntensity`, `MorphiiConfiguration`, and `MorphiiServiceDelegate`. The `MorphiiConfiguration` is an instance of the [MorphiiConfiguration](#morphiiconfiguration) object that configures how the morphii will be displayed. The `initialIntensity` is a Double that determines the starting intensity for the rendered morphiis. The `MorphiiSelectionViewDelegate` returns the `MorphiiConfiguration` of the selected morphii that can be used to create a new `BasicViewConfiguration` that can be used to add a new `BasicView` to allow the user to manipulate and utilize the selected morphii.

```swift
// Swift
func createSelectionView() -> MorphiiSelectionView? {
    let service = MorphiiService.sharedInstance()

    let morphiiConfig = MorphiiConfiguration(showName: true)
    morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)
    morphiiConfig.add(id: "6202185110939238400", name: nil, weight: 2)
    service.addSelectionView(withResponse: 1.0, config: morphiiConfig, delegate: self) //Adding selectionView with response to be returned in morphiiSelectionViewAdded
}

extension ViewController:MorphiiServiceDelegate {
    func morphiiSelectionViewAdded(_ morphiiSelectionView: MorphiiSelectionView) { // SelectionView is returned here to be added to view
        self.containerView.addSubview(morphiiSelectionView)
        print("Selection View Added")
    }
}
```

```objective-c
// Objective-C
-(MorphiiSelectionView*)createSelectionView {
    MorphiiService *service = [MorphiiService sharedInstance];   

    MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
    [morphiiConfig addWithId:@"6202185104333209600" name:nil weight:1];
    [morphiiConfig addWithId:@"6202185110939238400" name:nil weight:2];

    [service addSelectionViewWithResponse:1.0 config:morphiiConfig delegate:self]; //Adding selectionView with response to be returned in morphiiSelectionViewAdded

}

- (void) morphiiSelectionViewAdded:(MorphiiSelectionView *)morphiiSelectionView // SelectionView is returned here to be added to view
{
    [[self selectionView] addSubview:morphiiSelectionView];
}

```



#### Get Morphiis As Array

`public func getMorphiisAsArray(MorphiiConfiguration, withSize: Int, intensity: double) `

This method retrieves an array of morphiis and returns them in a callback delegate method `morphiiArrayReceived:(NSArray *)morphiis` . This method has three parameters: `MorphiiConfiguration`(which Morphiis to include),  `Size` (size of morphii Image as square ex. 110 would be considered 110x110), and `Intensity` (intensity at which the morphiis will show up).

```swift
// Swift
func createBasicView(containerView: UIView) -> BasicView {

    // Morphii configuration.
    let morphiiConfig = MorphiiConfiguration(showName: true)
    morphiiConfig.add(id: "6202184382145363968", name: nil, weight: 1)

    // Create the BasicViewConfiguration and add to the service.
    let config = BasicViewConfiguration(morphiiConfig: morphiiConfig, target: target, project: project, comment: comment, options: options, user: user)

    let service = MorphiiService.sharedInstance()
    service?.getMorphiisAsArray(morphiiConfig, withSize: 225, intensity: 1.0) //Array of Morphii objects will be returned in morphiiArrayReceived

}

extension ViewController:MorphiiServiceDelegate {

    func morphiiArrayReceived(_ morphiis: [Any]!) { //Morphii array is returned here
        print(morphiis as! [Morphii])
    }
}
```

```objective-c
// Objective-C
-(BasicView*)createBasicView: (UIView *)container {

    // Morphii information
    MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
    [morphiiConfig addWithId:@"6202184382145363968" name:nil weight:1];

    MorphiiService *service = [MorphiiService sharedInstance];    
    [service getMorphiisAsArray:morphiiConfig withSize:115 intensity:1.0];  //Array of Morphii objects will be returned in morphiiArrayReceived
}

- (void) morphiiArrayReceived:(NSArray *)morphiis{ //Morphii array is returned here
    _collectionView.dataSource = self;
    _collectionView.delegate = self;

    _morphiiArray = [NSArray arrayWithArray:morphiis];
    [_collectionView reloadData];
}
```

#### Submit
`public func submit (completion:@escaping ([ReactionResultRecord]) -> Void)`

This method submits data from all `BasicView`s currently in the app. The completion will pass back an `[ReactionResultRecord]`. This `Array` contains a [ReactionResultRecord](#reactionresultrecord) for each `BasicView` that was submitted with the method. The ReactionResultRecord also includes links to the png image of the Morphii at the intensity of which it was submitted.

```swift
//Swift
func submit () {
  MorphiiService.sharedInstance().submit { (records) in
    for record in records {
      print("Results Record");
      print("================================================");
      print("targetId: \(record.targetId)")
      print("viewId: \(record.viewId)")

      if !record.isSubmitted {
        // There was an error.
        print("error code: \(record.error?.code)")
        print("error message: \(record.error?.message)")
      }
      else {
        print("reactionId: \(record.reactionId)")

        if record.morphii != nil {
          print("morphii-id: \(record.morphii?.id)")
          print("morphii-name: \(record.morphii?.name)")
          print("morphii-displayName: \(record.morphii?.displayName)")
          print("morphii-intensity:  \(record.morphii?.intensity)")
          print("morphii-weight:  \(record.morphii?.weight)")
        }
        else {
          print("No morphii details provided.")
        }

        if record.comment != nil {
          print("comment-text: \(record.comment?.text)")
          print("comment-locale: \(record.comment?.locale)")
        }
        else {
          print("No comment field")
        }
      }

      print("================================================")
      print("================================================")
    }
  }
}
```

```objective-c
// Objective-C
- (void)submit {
  [[MorphiiService sharedInstance] submitWithCompletion:^(NSArray<ReactionResultRecord *> * _Nonnull records) {
    for (ReactionResultRecord *record in records) {
      NSLog(@"Results Record");
      NSLog(@"================================================");
      NSLog(@"targetId: %@",record.targetId);
      NSLog(@"viewId: %@",record.viewId);

      if (!record.isSubmitted) {
        // There was an error.
        NSLog(@"error code: %@",record.error.code);
        NSLog(@"error message: %@",record.error.message);
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
```

#### Reset
`public func reset (comment:Bool)`

This method resets all of the `BasicView`s to their default configuration. The method has one parameter: `comment`. This parameter is a boolean that if true will reset the comment field to its default value and if false will retain the user made changes.

```swift
// Swift
func reset() {
  MorphiiService.sharedInstance().reset(comment: true)
}
```

```objective-c
// Objective-C
- (void)reset {
  [[MorphiiService sharedInstance] resetWithComment:YES];
}
```

### <a name="basicview"></a>BasicView
These methods are similar to those found within the [MorphiiService](#morphiiservice) class but generally change in regards to the scope of what is affected when called.

#### Submit
`public func submit ( completion:@escaping (_ results:[ReactionResultRecord])->Void)`

This method takes the data from the specific `BasicView` and submits it. It will return an `[ReactionResultRecord]`. The `Array` will have one [ReactionResultRecord](#reactionresultrecord) since only one `BasicView` was submitted.

```swift
// Swift
func submit() {
  basicView?.submit { (records) in
    for record in records {
      print("Results Record");
      print("================================================");
      print("targetId: \(record.targetId)")
      print("viewId: \(record.viewId)")

      if !record.isSubmitted {
        // There was an error.
        print("error code: \(record.error?.code)")
        print("error message: \(record.error?.message)")
      }
      else {
        print("reactionId: \(record.reactionId)")

        if record.morphii != nil {
          print("morphii-id: \(record.morphii?.id)")
          print("morphii-name: \(record.morphii?.name)")
          print("morphii-displayName: \(record.morphii?.displayName)")
          print("morphii-intensity:  \(record.morphii?.intensity)")
          print("morphii-weight:  \(record.morphii?.weight)")
        }
        else {
          print("No morphii details provided.")
        }

        if record.comment != nil {
          print("comment-text: \(record.comment?.text)")
          print("comment-locale: \(record.comment?.locale)")
        }
        else {
          print("No comment field")
        }
      }

      print("================================================")
      print("================================================")
    }
  }
}
```

```objective-c
// Objective-C
- (void)submit {
  [_basicView submitWithCompletion:^(NSArray<ReactionResultRecord *> * _Nonnull records) {
    for (ReactionResultRecord *record in records) {
      NSLog(@"Results Record");
      NSLog(@"================================================");
      NSLog(@"targetId: %@",record.targetId);
      NSLog(@"viewId: %@",record.viewId);

      if (!record.isSubmitted) {
        // There was an error.
        NSLog(@"error code: %@",record.error.code);
        NSLog(@"error message: %@",record.error.message);
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
```

#### <a name="reset"></a>Reset
`public func reset (comment:Bool)`

This method will reset the `BasicView` back to its default values. The method requires one parameter: `comment`. This parameter is a boolean that when marked true will reset the comment field to its default value and if false will retain the user made changes.

```swift
// Swift
func reset() {
  basicView?.reset(comment: true)
}
```

```objective-c
// Objective-C
- (void)reset {
  [_basicView resetWithComment:YES];
}
```

### <a name="morphiiselectionview"></a>MorphiiSelectionView
The MorphiiSelectionView is a view that contains a list of morphiis. This object is returned by [AddSelectionView](#addselectionview)


### Supporting Classes
These are the supporting classes as parameters in [MorphiiService](#morphiiservice), [MorphiiSelectionView](#morphiiselectionview), and [BasicView](#basicview) methods.

#### <a name="project"></a>Project
This class is used to group different project data. It requires two parameters: `id` and `description`. The `id` is a String that is used to label the project. The `description` is a String that briefly describes the project. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// Project information
let project = Project(id: "my-project-id", description: "My Project Description")
```

```objective-c
// Objective-C
// Project information
Project *project = [[Project alloc] initWithId:@"my-project-id" description:@"My project description"];
```

#### <a name="target"></a>Target
The `Target` class is utilized to describe what the morphii will be in reference to. The class requires three parameters: `id`, `type`, and `metadata`. The `id` is a String that serves as a label for the referenced object. The `type` is a String that describes what the `Target` is. The `type` should be a value like: question, image, video, article, etc. The `metadata` object is a dictionary of additional information the developer would like to maintain a record of; this parameter can be `nil`. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// Target information
let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2", "value-3" : "key3"]
let target = Target(id: "test-target-id-1", type: "question", metadata: metadata)
```

```objective-c
// Objective-C
// Target info
NSDictionary *metadata = @{@"value-1":@"key1", @"value-2":@"key2"};
Target *target = [[Target alloc] initWithId:@"my-target-id" type:@"question" metadata:metadata];
```

#### <a name="user"></a>User
This class is used to define the user that is interacting with the morphii. It uses three parameters: `id`, `type`, and `properties`. The `id` is a String that serves as the id for the user. The `type` is a String that defines the type of user. Choices for the `type` include: external, facebook, twitter, or google. The `properties` parameter is a dictionary that the developer may use to collect any additional information they desire; this parameter may be `nil`. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// User information
let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
let user = User(id: "user-id", type: "external", properties: properties)
```

```objective-c
// Objective-C
// User information
NSDictionary *properties = @{@"user.name@mailinator.com":@"email", @"value-2":@"key2", @"value-3":@"key3"};
User *user = [[User alloc] initWithId:@"user-id" type:@"external" properties:properties];
```

#### <a name="comment"></a>Comment
This class is used to configure the comment section of a [BasicView](#basicview). The class requires five parameters: `show`, `required`, `maxLength`, `label`, and `hintText`. The `show` parameter is a boolean that determines whether the comment section will be visible or not. The `required` parameter is a boolean that determines whether the user is required to fill in a comment in order to submit the BasicView. The `maxLength` parameter is an int that determines the maximum amount of characters allowed in a comment; if set to 0 an unlimited amount of characters are allowed. The `label` parameter is a String that appears above the comment field. The `hintText` is a String that will display within the comment field. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// Comment configuration
let comment = Comment(show: false, required: false, maxLength: 100, label: "Post", hintText: "Post Here")
```

```objective-c
// Objective-C
// Comment info
Comment *comment = [[Comment alloc] initWithShow:NO required:NO maxLength:100 label:@"Comment" hintText:@"Enter comment"];
```

#### <a name="options"></a>Options
This class is used to define additional configuration. It requires two parameters: `stage` and `initialIntensity`. The `stage` parameter is a String that has three options: `test`, `validation`, and `live`. The `test` option will have no data processed by the data analytics pipeline. The `validation` option will send data to be processed by the analytics pipeline but will not show up in any report data. The `live` option will have data be processed through all stages of the data analytics pipeline and report data. The `initialIntensity` parameter is a double that determines the starting intensity of the morphii. This value is required to be between 0 and 1. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// Options configuration
let options = Options(stage: "live", initialIntensity: 0.5)
```

```objective-c
// Objective-C
// Options configuration
Options *options = [[Options alloc] initWithStage:@"live" initialIntensity:0.5];
```
#### <a name="applicationInformation"></a>Application Information
This optional class is used to define additional information about the application/project using the MorphiiSDK. It requires four parameters: `name` , `description`, `version` , and `properties` . The `name` , `description`, and `version` parameters are all Strings. The `properties` parameter is a dictionary that can contain any developer defined information. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration).

```swift
// Swift
// Application Information
let appInfo = ApplicationInformation(name: "Test App", description: "Test App Desc", version: "1.0", andProperties: nil)
```

```objective-c
// Objective-C
// Application Information
ApplicationInformation* appInfo = [[ApplicationInformation alloc] initWithName:@"Test App" description:@"Test App Desc" version:@"1.0" andProperties:nil];
```

#### <a name="morphiiconfiguration"></a>MorphiiConfiguration
This class is used to define the default configuration of the morphii. The `MorphiiConfiguration` object takes one parameter: `showName`. This parameter is a boolean that when true, will display the name below the morphii. When false the name will not be shown. After creating a `MorphiiConfiguration` object it is necessary to call its `add` method in order to add information to the configuration. The method requires three parameters: `id`, `name`, `weight`. The `id` is a String that determines which morphii will be added. The `name` is a developer defined label for the morphii. This parameter can be defined as `null`. If `null` the default morphii name will be used. The `weight` parameter is an int that is used to assign a weight to the morphii. This object is used to construct the [BasicViewConfiguration](#basicviewconfiguration) and add a [MorphiiSelectionView](#morphiiselectionview).

##### Methods
- `public func add(id: String, name: String?, weight: Int = 0)` : This method adds a specific morphii to the MorphiiConfiguration.

```swift
// Swift
// Morphii configuration.
let morphiiConfig = MorphiiConfiguration(showName: true)
morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)
```

```objective-c
// Objective-C
MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
[morphiiConfig addWithId:@"6202185104333209600" name:nil weight:1];
```


#### <a name="basicviewconfiguration"></a>BasicViewConfiguration
This class defines the [BasicView](#basicview) configuration. It is used to create a new `BasicView`. The object requires six parameters: `morphiiConfiguration`, `target`, `project`, `comment`, `options`, `user`. Reference above for aid in creating these objects.

BasicViewConfiguration now includes the ability to add a slider(either horizontal or vertical) instead of having the user interact with Morphiis with touch gestures as well as the attachment of ApplicationInformation, mentioned previously. To allow users to interact with the MorphiiView using a slider bar, set the showSlider boolean value to true. This adds a horizontal slider bar to the MorphiiView. If you would like to make the slider bar vertical you must have the showSlider boolean value set to true in addition to setting the showSliderVertical boolean value to true.  If the showSliderVertical boolean is set to true but the showSlider boolean is set to false, no slider bar will be presented.  When a slider bar is present, the normal touch gestures of the view will be deactivated.

```swift
// Swift
// Project information
let project = Project(id: "my-project-id", description: "My Project Description")

// Target information
let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2"]
let target = Target(id: "test-target-id-1", type: "question", metadata: metadata)

// Options configuration
let options = Options(stage: "test", initialIntensity: 0.5)

// Comment configuration
let comment = Comment(show: true, required: true, maxLength: 100, label: "Post", hintText: "Post Here")

// User information
let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
let user = User(id: "user-id", type: "external", properties: properties)

// Application configuration
let appInfo = ApplicationInformation(name: "Test App", description: "Test App Desc", version: "1.0", andProperties: nil)

// Morphii configuration.
let morphiiConfig = MorphiiConfiguration(showName: true)
morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)

let config = BasicViewConfiguration(morphiiConfig: morphiiConfig, target: target, project: project, comment: comment, options: options, user: user)
config.application = appInfo
config.showSlider = true //Setting showSlider to true places a horizontal slider bar on the view by default.
config.showSliderVertical = true //Setting showSliderVertical to true places a vertical slider bar on the view. showSliderVertical only works when showSlider is also true.
```

```objective-c
// Objective-C
// Project information
Project *project = [[Project alloc] initWithId:@"my-project-id" description:@"My project description"];

// Target info
NSDictionary *metadata = @{@"value-1":@"key1", @"value-2":@"key2"};
Target *target = [[Target alloc] initWithId:@"my-target-id" type:@"question" metadata:metadata];

// Options info
Options *options = [[Options alloc] initWithStage:@"live" initialIntensity:0.5];

// Comment info
Comment *comment = [[Comment alloc] initWithShow:NO required:NO maxLength:100 label:@"Comment" hintText:@"Enter comment"];

// User data
NSDictionary *properties = @{@"user.name@mailinator.com":@"email", @"value-2":@"key2", @"value-3":@"key3"};
User *user = [[User alloc] initWithId:@"user-id" type:@"external" properties:properties];

// Application Information
ApplicationInformation* appInfo = [[ApplicationInformation alloc] initWithName:@"Test App" description:@"Test App Desc" version:@"1.0" andProperties:nil];

// Morphii information
MorphiiConfiguration *morphiiConfig = [[MorphiiConfiguration alloc] initWithShowName:YES];
[morphiiConfig addWithId:@"6202185104333209600" name:nil weight:1];

BasicViewConfiguration *config = [[BasicViewConfiguration alloc] initWithMorphiiConfig:morphiiConfig target:target project:project comment:comment options:options user:user];
config.application = appInfo;
config.showSlider = YES; //Setting showSlider to true places a horizontal slider bar on the view by default.
config.showSliderVertical = YES; //Setting showSliderVertical to true places a vertical slider bar on the view. showSliderVertical only works when showSlider is also true.
```

#### <a name="reactionresultrecord"></a>ReactionResultRecord
The ReactionResultRecord object is returned from the `submit` methods. Note, if account subscription expires or record limit is met the ReactionResultRecord object will not return the details in the [ReactionMorphiiResultRecord](#reactionmorphiiresultrecord) and [ReactionCommentRecord](#reactioncommentrecord) objects.

##### Properties
- `isSubmitted: Bool`  : True if the reaction was successfully submitted.
- `reactionId: String?` : Returns the reaction id generated for this reaction.
- `viewId: String` : Returns the view id.
- `targetId: String` : Returns the target id associated with this reaction.
- `comment: ReactionCommentRecord?`: Returns an [ReactionCommentRecord](#reactioncommentrecord) object which contains more details about the reaction comment.
- `morphii: ReactionMorphiiResultRecord?` : Returns an [ReactionMorphiiResultRecord](#reactionmorphiiresultrecord) object which contains more details about the reaction morphii.
- `error: ReactionError?` : Returns an [ReactionError](#reactionerror) object which contains more details about the reaction error.

```swift
// Swift
func submit() {
  MorphiiService.sharedInstance().submit { (records) in
    for record in records {
      print("Results Record");
      print("================================================");
      print("targetId: \(record.targetId)")
      print("viewId: \(record.viewId)")

      if !record.isSubmitted {
        // There was an error.
        print("error code: \(record.error?.code)")
        print("error message: \(record.error?.message)")
      }
      else {
        print("reactionId: \(record.reactionId)")

        if record.morphii != nil {
          print("morphii-id: \(record.morphii?.id)")
          print("morphii-name: \(record.morphii?.name)")
          print("morphii-displayName: \(record.morphii?.displayName)")
          print("morphii-intensity:  \(record.morphii?.intensity)")
          print("morphii-weight:  \(record.morphii?.weight)")
        }
        else {
          print("No morphii details provided.")
        }

        if record.comment != nil {
          print("comment-text: \(record.comment?.text)")
          print("comment-locale: \(record.comment?.locale)")
        }
        else {
          print("No comment field")
        }
      }

      print("================================================")
      print("================================================")
    }
  }
}
```

```objective-c
// Objective-C
- (void)submit {
  [[MorphiiService sharedInstance] submitWithCompletion:^(NSArray<ReactionResultRecord *> * _Nonnull records) {
    for (ReactionResultRecord *record in records) {
      NSLog(@"Results Record");
      NSLog(@"================================================");
      NSLog(@"targetId: %@",record.targetId);
      NSLog(@"viewId: %@",record.viewId);

      if (!record.isSubmitted) {
        // There was an error.
        NSLog(@"error code: %@",record.error.code);
        NSLog(@"error message: %@",record.error.message);
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
```

#### <a name="reactionmorphiiresultrecord"></a>ReactionMorphiiResultRecord
This object contains detail information for the morphii associated with the [ReactionResultRecord](#reactionresultrecord).

##### Properties
- `id: String` : Returns the unique morphii id associated with this reaction.
- `name: String` : Returns the morphii name associated with this reaction.
- `displayName: String` : Returns the morphii display name associated with this reaction.
- `intensity: Double` : Returns the morphii intensity associated with this reaction.
- `weight: Int` : Returns the morphii weight associated with this reaction.
- `partName: String` : Returns the current partName of a multi-reaction Morphii.
- `parts: Array` : Returns the parts title of a multi-reaction Morphii.
- `urls: Dictionary` : Returns the Morphii image urls.


#### <a name="reactioncommentrecord"></a>ReactionCommentRecord
This object contains detail information for the user entered comment associated with the [ReactionResultRecord](#reactionresultrecord).

##### Properties
- `text: String` : Returns the comment text associated with this reaction.
- `locale: String` : Returns the comment locale associated with this reaction.

#### <a name="reactionerror"></a>ReactionError
This object gives further details into any errors that may have occurred during the submission process. It contains two properties: `code` and `message`. The `code` property is a specific error code defined by the data analytics pipeline. The `message` property is a message associated with the `code` property that explains what caused the error.

##### Properties
- `code: String` : Returns reaction error code string.
- `message: String` : Returns reaction error message string.
