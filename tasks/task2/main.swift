//
//  main.swift
//  2
//
//  Created by Кривогузов Владислав on 15.06.18.
//  Copyright © 2018 Кривогузов Владислав. All rights reserved.
//

import Foundation

var str = "Раз Дваа Дваа ТрИиИи ТрИиИи Четырее автомобильвап"

func branch1(string str: String) -> Double{
    let wordArray = str.components(separatedBy: " ")
    print(wordArray)
    var averageCharCount = 0.0
    for word in wordArray {
        averageCharCount+=Double(word.count)
    }
    averageCharCount/=Double(wordArray.count)
    return averageCharCount
}
/**
 - returns: Словарь из слов с количством гласных больше 3
 */
func branch2(string str: String) -> [String: Int]{
    let wordArray = str.components(separatedBy: " ")
    var dic = [String: Int]();
    for word in wordArray{
        var count = 0
        for c in word{
            switch String(c).lowercased(){
            case "а","о","е","у","ы","э","я","и","ю":
                count += 1
            default: break
            }
            if (count >= 4)
            {
                dic[word] = count
            }
        }
    }
    return dic
}
print(str)
print("Средняя длина слова \(branch1(string: str))")
let dic = branch2(string: str)
print("Число слов, где гласных больше 3 = \(dic.count)")
print("Вот эти слова \(dic)")


