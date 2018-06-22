//
//  ViewController.swift
//  task7
//
//  Created by AndreyButyrchik on 21.06.18.
//  Copyright © 2018 AndreyButyrchik. All rights reserved.
//

import UIKit
import CoreData

class ViewController: UIViewController {

    @IBOutlet weak var name: UITextField!
    @IBOutlet weak var birthYear: UITextField!
    @IBOutlet weak var gender: UITextField!
    @IBOutlet weak var height: UITextField!
    @IBOutlet weak var weight: UITextField!
    @IBAction func next(_ sender: Any) {
        if name.text != "" && birthYear.text != "" && gender.text != "" && height.text != "" && weight.text != "" {
            let appDelegate = UIApplication.shared.delegate as! AppDelegate
            let context = appDelegate.persistentContainer.viewContext
            let newUser = NSEntityDescription.insertNewObject(forEntityName: "User", into: context)
            newUser.setValue(name.text, forKey: "name")
            newUser.setValue(Int(birthYear.text!), forKey: "birthYear")
            newUser.setValue(gender.text, forKey: "gender")
            newUser.setValue(Int(height.text!), forKey: "height")
            newUser.setValue(Int(weight.text!), forKey: "weight")
            do {
                try context.save()
            } catch {
                print("error")
            }
        }
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

