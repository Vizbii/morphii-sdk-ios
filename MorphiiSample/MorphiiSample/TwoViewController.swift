//
//  TwoViewController.swift
//  MorphiiSample
//

import UIKit
import MorphiiSDK

class TwoViewController: UIViewController {
    @IBOutlet weak var containerView: UIView!

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        let morphiiConfig = MorphiiConfiguration(showName: true)
        morphiiConfig.add(id: "6202185104333209600", name: nil, weight: 1)
        morphiiConfig.add(id: "6202185110939238400", name: nil, weight: 2)
        morphiiConfig.add(id: "6202184384670334976", name: nil, weight: 3)
        morphiiConfig.add(id: "6202173597625090048", name: nil, weight: 4)
        morphiiConfig.add(id: "6202173597771890688", name: nil, weight: 5)
        if let morphiiSelectionView = MorphiiService.sharedInstance().addSelectionView(initialIntensity: 1.0, config: morphiiConfig, delegate: self) {
            self.containerView.addSubview(morphiiSelectionView)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

extension TwoViewController:MorphiiSelectionViewDelegate {
    func selectedMorphii(morphiiConfiguration: MorphiiConfiguration) {
        guard let nextView = storyboard?.instantiateViewController(withIdentifier: "SelectedMorphiiViewController") as? SelectedMorphiiViewController else {return}
        nextView.morphiiConfiguration = morphiiConfiguration
        present(nextView, animated: true, completion: nil)
    }
}
