//
//  SelectedMorphiiViewController.swift
//  MorphiiSample
//

import UIKit
import MorphiiSDK

class SelectedMorphiiViewController: UIViewController {
    @IBOutlet weak var containerView: UIView!

    var morphiiConfiguration:MorphiiConfiguration!
    var basicView:BasicView?

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
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
        let target = Target(id: "test-target-id-2", type: "question", metadata: metadata)

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
    @IBAction func backButtonPressed(_ sender: UIButton) {
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
                    print("error code: \(String(describing: record.error?.code))")
                    print("error message: \(String(describing: record.error?.message))")
                }
                else {
                    print("reactionId: \(String(describing: record.reactionId))")
                    
                    if record.morphii != nil {
                        print("morphii-id: \(String(describing: record.morphii?.id))")
                        print("morphii-name: \(String(describing: record.morphii?.name))")
                        print("morphii-displayName: \(String(describing: record.morphii?.displayName))")
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
            
            let alertController = UIAlertController(title: "Submitted", message: "Your morphii has been successfully submitted!", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
            self.present(alertController, animated: true, completion: nil)
        }
    }
}

extension SelectedMorphiiViewController:BasicViewDelegate {
    func commentChange(type: String, commentRequiredValid: Bool, view: BasicView.BasicViewObject) {
        print("Event type: \(type)")
        print("viewId: \(view.id)")
        if type == "comment_changed" {
            print("comment required: \(String(describing: view.comment?.required))")
            print("comment length: \(String(describing: view.comment?.length))")
            print("comment value: \(String(describing: view.comment?.value))")
        }        
    }
}
