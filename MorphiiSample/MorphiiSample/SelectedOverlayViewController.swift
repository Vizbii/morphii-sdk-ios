//
//  SelectedOverlayViewController.swift
//  MorphiiSample
//

import UIKit
import MorphiiSDK

class SelectedOverlayViewController: UIViewController {
    var morphiiConfiguration:MorphiiConfiguration!
    @IBOutlet weak var overlayView: UIView!
    var basicView:BasicView?
    @IBOutlet weak var containerView: UIView!

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        overlayView.layer.cornerRadius = 8.0
        overlayView.clipsToBounds = true
        addBasicView(containerView: containerView, morphiiConfiguration: morphiiConfiguration)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
        let target = Target(id: "test-target-id-3", type: "question", metadata: metadata)

        // Create User
        let properties: NSDictionary? = ["user@mailinator.com" : "email", "value-2" : "key2", "value-3" : "key3"]
        let user = User(id: "user-id", type: "external", properties: properties)
        
        // Options configuration
        let options = Options(stage: "test", initialIntensity: 0.5)

        // Comment configuration
        let comment = Comment(show: false, required: false, maxLength: 100, label: "Post", hintText: "Post Here")
        
        // Create the BasicViewConfiguration and add to the service.
        let config = BasicViewConfiguration(morphiiConfig: morphiiConfiguration, target: target, project: project, comment: comment, options: options, user: user)
        basicView = service.add(containerView: containerView, config: config, delegate: self)
        containerView.addSubview(self.basicView!)
    }
    
    @IBAction func doneButtonPressed(_ sender: UIButton) {
        dismiss(animated: true, completion: nil)
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
            
            let alertController = UIAlertController(title: "Submitted", message: "Your morphii has been successfully submitted!", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
            self.present(alertController, animated: true, completion: nil)
        }
    }
}

extension SelectedOverlayViewController:BasicViewDelegate {
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
