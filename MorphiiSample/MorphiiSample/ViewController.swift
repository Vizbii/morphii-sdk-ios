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
        service.authenticate(username: "<user_name>", password: "<user_password>", accountId: "<account_id>") { (result) in
            if result.isAuthenticated {
                let morphiiConfig = MorphiiConfiguration(showName: true)
                morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)
                morphiiConfig.add(id: "6202185110939238400", name: nil, weight: 2)
                morphiiConfig.add(id: "6202184384670334976", name: nil, weight: 3)
                morphiiConfig.add(id: "6202173597625090048", name: nil, weight: 4)
                morphiiConfig.add(id: "6202173597771890688", name: nil, weight: 5)
                if let morphiiSelectionView = service.addSelectionView(initialIntensity: 1.0, config: morphiiConfig, delegate: self) {
                    self.containerView.addSubview(morphiiSelectionView)
                }
            }
            else {
                print("Authentication failed")
                print("error code: \(result.error?.code)")
                print("error message: \(result.error?.message)")
            }
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func submitButtonPressed(_ sender: UIButton) {
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

    @IBAction func getPngButtonPressed(_ sender: UIButton) {
        imageView.image = basicView?.png(size: CGSize(width: 60, height: 60))
    }
    
    @IBAction func resetButtonPressed(_ sender: UIButton) {
        MorphiiService.sharedInstance().reset(comment: true)
    }
    
    func addBasicView (containerView:UIView, morphiiConfiguration:MorphiiConfiguration) {
        let service = MorphiiService.sharedInstance()
        for subView in containerView.subviews {
            subView.removeFromSuperview()
        }
        
        // Remove the basic view from the service.
        if let basic = basicView {
            service.remove(basicView: basic)
        }
        
        // Create Project
        let project = Project(id: "my-project-id", description: "My Project Description")
        service.project = project
        
        // Create Target
        let metadata: NSDictionary? = ["value-1" : "key1", "value-2" : "key2", "value-3" : "key3"]
        let target = Target(id: "test-target-id-1", type: "question", metadata: metadata)

        // Create User
        let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
        let user = User(id: "user-id", type: "external", properties: properties)

        // Options configuration
        let options = Options(stage: "test", initialIntensity: 0.5)
        
        // Comment configuration
        let comment = Comment(show: true, required: true, maxLength: 100, label: "Post", hintText: "Post Here")

        // Create the BasicViewConfiguration and add to the service.
        let config = BasicViewConfiguration(morphiiConfig: morphiiConfiguration, target: target, project: project, comment: comment, options: options, user: user)
        basicView = service.add(containerView: containerView, config: config, delegate: self)
        containerView.addSubview(self.basicView!)
    }
    
}

extension ViewController:MorphiiSelectionViewDelegate {
    func selectedMorphii(morphiiConfiguration: MorphiiConfiguration) {
        self.addBasicView(containerView: containerView2, morphiiConfiguration: morphiiConfiguration)
    }
}

extension ViewController:BasicViewDelegate {
    func commentChange(type: String, commentRequiredValid: Bool, view: BasicView.BasicViewObject) {
        print("Event type: \(type)")
        print("viewId: \(view.id)")
        if type == "comment_changed" {
            print("comment required: \(view.comment?.required)")
            print("comment length: \(view.comment?.length)")
            print("comment value: \(view.comment?.value)")
        }        
    }
}

