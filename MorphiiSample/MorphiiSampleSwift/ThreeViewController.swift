//
//  ThreeViewController.swift
//  MorphiiSample
//

import UIKit
import MorphiiSDK

class ThreeViewController: UIViewController {
    @IBOutlet weak var containerView:UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        let morphiiConfig = MorphiiConfiguration(true)
        morphiiConfig?.add(withID: "6439955463778914304", name: nil, weight: 1)  // bi-directional morphii
        morphiiConfig?.add(withID: "6387684990323101696", name: nil, weight: 2)
        morphiiConfig?.add(withID: "6387687516724666368", name: nil, weight: 3)
        morphiiConfig?.add(withID: "6387687738608865280", name: nil, weight: 4)
        morphiiConfig?.add(withID: "6387686352809422848", name: nil, weight: 5)
        morphiiConfig?.add(withID: "6387687144609767424", name: nil, weight: 6)
        morphiiConfig?.add(withID: "6387687069345202176", name: nil, weight: 7)
        morphiiConfig?.add(withID: "6387687641635434496", name: nil, weight: 8)

        if let morphiiSelectionView = MorphiiService.sharedInstance().addSelectionView(withIntensity: 1.0, config: morphiiConfig, delegate: self) {
            self.containerView.addSubview(morphiiSelectionView)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

extension ThreeViewController:MorphiiSelectionViewDelegate {
    func selectedMorphii(_ morphiiConfiguration: MorphiiConfiguration) {
        guard let nextView = storyboard?.instantiateViewController(withIdentifier: "SelectedOverlayViewController") as? SelectedOverlayViewController else {return}
        nextView.morphiiConfiguration = morphiiConfiguration
        present(nextView, animated: true, completion: nil)
    }
}
