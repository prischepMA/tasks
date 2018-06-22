//
//  ViewController.swift
//  task10
//
//  Created by AndreyButyrchik on 21.06.18.
//  Copyright © 2018 AndreyButyrchik. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var segment: UISegmentedControl!
    private var octagram: CAShapeLayer!
    override func viewDidLoad() {
        super.viewDidLoad()
        drawOctagram()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func choose(_ sender: Any) {
        switch segment.selectedSegmentIndex {
        case 1:
            scale()
            break;
        case 2:
            move()
            break;
        case 3:
            roundCorn()
            break;
        default:
            break;
        }
    }
    
    private func roundCorn() {
        let roundAnimation = CABasicAnimation(keyPath: #keyPath(CAShapeLayer.cornerRadius))
        roundAnimation.fromValue = 0.0
        roundAnimation.toValue = 50.0
        roundAnimation.duration = 2
        octagram.add(roundAnimation, forKey: nil)
        octagram.cornerRadius = 50.0
    }
    
    private func move() {
        let moveAnimation = CABasicAnimation(keyPath: #keyPath(CAShapeLayer.path))
        moveAnimation.fromValue = octagram.path
        moveAnimation.toValue = octagramPath(center: CGPoint(x: 200, y: 200), radius: 50).cgPath
        moveAnimation.duration = 2
        
        octagram.add(moveAnimation, forKey: nil)
    }
    
    private func scale() {
        let scaleAnimation = CABasicAnimation(keyPath: #keyPath(CAShapeLayer.transform))
        scaleAnimation.valueFunction = CAValueFunction(name: kCAValueFunctionScale)
        scaleAnimation.fromValue = [1,1,0]
        scaleAnimation.toValue = [2,2,0]
        scaleAnimation.duration = 2
        
        octagram.add(scaleAnimation, forKey: nil)
    }
    
    private func drawOctagram() {
        octagram = CAShapeLayer()
        let path = octagramPath(center: CGPoint(x: 50, y: 200),
                                radius: 50)
        octagram.path = path.cgPath
        octagram.frame = path.bounds
        
        view.layer.addSublayer(octagram)
        
        let gradient = CAGradientLayer()
        gradient.frame = self.view.bounds
        gradient.colors = [UIColor.red.cgColor, UIColor.green.cgColor]
        gradient.startPoint = CGPoint(x: 0, y: 1)
        gradient.endPoint = CGPoint(x: 1, y: 0)
        
        gradient.mask = octagram
        view.layer.addSublayer(gradient)
    }
    
    private func octagramPath(center: CGPoint,
                              radius: CGFloat) -> UIBezierPath {
        let brush = UIBezierPath()
        /*var points: [CGPoint] = []
        let angle = CGFloat(Double.pi / 2)
        
        for i in 0...5 {
            points.append(CGPoint(x : center.x + radius*cos(angle*CGFloat(i)),
                                  y : center.y + radius*sin(angle*CGFloat(i))))
        }
        
        brush.move(to: points[0]);
        brush.addLine(to: points[1])
        brush.addLine(to: points[2])
        brush.addLine(to: points[3])
        brush.close()*/
        brush.move(to: CGPoint(x: center.x,y: center.y + radius))
        brush.addLine(to: CGPoint(x: center.x+radius*cos(.pi/10),y: center.y+radius*sin(.pi/10)))
        brush.addLine(to: CGPoint(x: center.x+radius*sin(.pi*1/5),y: center.y-radius*cos(.pi*1/5)))
        brush.addLine(to: CGPoint(x: center.x-radius*sin(.pi*1/5),y: center.y-radius*cos(.pi*1/5)))
        brush.addLine(to: CGPoint(x: center.x-radius*cos(.pi/10),y: center.y+radius*sin(.pi/10)))
        brush.addLine(to: CGPoint(x: center.x,y: center.y+radius))
        brush.close()
        return brush
    }
}

