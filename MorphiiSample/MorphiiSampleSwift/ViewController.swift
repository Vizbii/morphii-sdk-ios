//
//  ViewController.swift
//  MorphiiSample
//

import UIKit
import MorphiiSDK

class ViewController: UIViewController {
    @IBOutlet weak var containerView: UIView!
    @IBOutlet weak var containerView2: UIView!
    @IBOutlet weak var imageView: UIImageView!
    var basicView:BasicView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let service = MorphiiService.sharedInstance()
        service?.serviceDelegate = self
        //Setting API Key Required. You may set with or Without a subaccount
        //service?.setAPIKey("pJEOKdYSqd4cUxJNbuX3G294G4GuRdT2ak7D5OMu", accountId: "17253015")
        service?.setAPIKey("pJEOKdYSqd4cUxJNbuX3G294G4GuRdT2ak7D5OMu", accountId: "17253015", withSubAccountID: "test-sub-id", andSubAccountName: "test-sub-name")
        
        
        let morphiiConfig = MorphiiConfiguration(true)
        morphiiConfig?.add(withID: "6439955463778914304", name: nil, weight: 1)  // bi-directional morphii
        morphiiConfig?.add(withID: "6387684990323101696", name: nil, weight: 2)
        morphiiConfig?.add(withID: "6387687516724666368", name: nil, weight: 3)
        morphiiConfig?.add(withID: "6387687738608865280", name: nil, weight: 4)
        morphiiConfig?.add(withID: "6387686352809422848", name: nil, weight: 5)
        morphiiConfig?.add(withID: "6387687144609767424", name: nil, weight: 6)
        morphiiConfig?.add(withID: "6387687069345202176", name: nil, weight: 7)
        morphiiConfig?.add(withID: "6387687641635434496", name: nil, weight: 8)


        /***********METHODS WITHOUT DELEGATES***********/
        /*** Uncomment to Present a scrollView of morphiis with no delegate methods.
         service?.addSelectionView(withIntensity: 1.0, config: morphiiConfig, delegate: self)
         */
        
        
        /***********METHODS WITH DELEGATES***********/
        /*** Uncomment to Present a scrollView of morphiis with delegate methods.*/
         service?.addSelectionView(withResponse: 1.0, config: morphiiConfig, delegate: self)
        
        /*** Uncomment to collect morphiis as an array, Morphii Objects have an Image Property For Display
        [service?.getMorphiisAsArray(morphiiConfig, withSize: 225, intensity: 1.0)
        */
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func submitButtonPressed(_ sender: UIButton) {
        MorphiiService.sharedInstance().submit { (records) in
            for record:ReactionResultRecord in records! {
                print("Results Record");
                print("================================================");
                print("targetId: \(record.targetId)")
                print("viewId: \(record.viewId)")
                
                if !record.isSubmitted {
                    // There was an error.
                    print("error code: \(String(describing: record.error?.code))")
                    print("error message: \(String(describing: record.error?.message))")
                }
                else {
                    print("reactionId: \(String(describing: record.reactionId))")
                    
                    if record.morphii != nil {
                        print("morphii-id: \(String(describing: record.morphii?.id))")
                        print("morphii-name: \(String(describing: record.morphii?.name))")
                        print("morphii-displayName: \(String(describing: record.morphii?.displayName))")
                        print("morphii-partName: \(String(describing: record.morphii?.partName))")
                        print("morphii-intensity:  \(String(describing: record.morphii?.intensity))")
                        print("morphii-weight:  \(String(describing: record.morphii?.weight))")
                    }
                    else {
                        print("No morphii details provided.")
                    }
                    
                    if record.comment != nil {
                        print("comment-text: \(String(describing: record.comment?.text))")
                        print("comment-locale: \(String(describing: record.comment?.locale))")
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
    
    @IBAction func resetButtonPressed(_ sender: UIButton) {
        MorphiiService.sharedInstance().reset(withComment: true)
    }
    
    func addBasicView (containerView:UIView, morphiiConfiguration:MorphiiConfiguration) {
        let service = MorphiiService.sharedInstance()
        
        for subView in containerView.subviews {
            subView.removeFromSuperview()
        }
        
        // Remove the basic view from the service.
        if let basic = basicView {
            service?.remove(basic)
        }
        
        // Create Project
        let project = Project("my-project-id", withDescription: "My Project Description")
        service?.project = project
        
        // Create Target
        let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2", "value-3" : "key3"]
        let target = Target(id: "test-target-id-1", withType: "question", andData: metadata as! [AnyHashable : Any])
        
        // Create User
        let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
        let user = User(id: "user-id", withType: "external", andProperties: properties as! [AnyHashable : Any])
        
        // Options configuration
        let options = Options("test", withIntensity: 0.5)
        
        // Comment configuration
        let comment = Comment(false, isRequired: true, withMaxLength: 100, label: "Post", andHintText: "Post Here")
        
        // Application configuration
        let appInfo = ApplicationInformation(name: "Test App", description: "Test App Desc", version: "1.0", andProperties: nil)
        
        // Create the BasicViewConfiguration and add to the service.
        let config = BasicViewConfiguration(morphiiConfig: morphiiConfiguration, target: target, project: project, comment: comment, options: options, user: user)
        config?.application = appInfo
        config?.showSlider = false;
        config?.showSliderVertical = false;
        
        /***********METHODS WITHOUT DELEGATES***********/
        /*** Uncomment to Present a basicView for a morphii to adjust intensity with delegate methods.
        self.basicView = service.add(containerView: containerView, config: config, delegate: self)
        containerView.addSubview(self.basicView!)
        */
        
        /***********METHODS WITH DELEGATES***********/
        
        /*** Uncomment to Present a basicView for a morphii to adjust intensity with delegate methods.*/
        service?.addBasicView(withResponse: containerView, config: config, delegate: self)
        
    }
    
}

extension ViewController:MorphiiServiceDelegate {
    func morphiiSelectionViewAdded(_ morphiiSelectionView: MorphiiSelectionView) {
        self.containerView.addSubview(morphiiSelectionView)
        print("Selection View Added")
    }
    func morphiiBasicViewAdded(_ basicView: BasicView) {
        self.basicView = basicView
        containerView2.addSubview(self.basicView!)
        print("Basic View Added")
    }
    func morphiiArrayReceived(_ morphiis: [Any]!) {
        print(morphiis as! [Morphii])
    }
    
}

extension ViewController:MorphiiSelectionViewDelegate {
    func selectedMorphii(_ morphiiConfiguration: MorphiiConfiguration) {
        self.addBasicView(containerView: containerView2, morphiiConfiguration: morphiiConfiguration)
    }
}

extension ViewController:BasicViewDelegate {
    func commentChange(_ type: String!, commentRequiredValid: Bool, view: BasicViewObject!) {
        print("Event type: \(type)")
        print("viewId: \(view.id)")
        if type == "comment_changed" {
            print("comment required: \(String(describing: view.comment?.required))")
            print("comment length: \(String(describing: view.comment?.length))")
            print("comment value: \(String(describing: view.comment?.value))")
        }
    }
    

}

