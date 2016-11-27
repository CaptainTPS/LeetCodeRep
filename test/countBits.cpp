//
//  countBits.cpp
//  test
//
//  Created by TPS on 2016/10/1.
//  Copyright © 2016年 TPS. All rights reserved.
//

#include <iostream>
#include "string"
#include <vector>

using namespace std;

vector<int> countBits(int num) {
    vector<int> m;
    m.push_back(0);
    if (num == 0) {
        return m;
    }
    m.push_back(1);
    if (num == 1) {
        return m;
    }
    int count = 2;
    
    int start_before = 1;
    int end_before = 1;
    
    int start = 2;
    int half = 2;
    int end = 3;
    int now = start;
    
    while (count <= num) {
        
        if (now <= half) {
            m.push_back(m[start_before+now-start]);
        }else if(now > half && now<=end){
            m.push_back(m[start_before+now-half-1]+1);
        }else{
            start_before = start;
            end_before = end;
            start = start * 2;
            end = start*2 -1;
            half = (start + end)/2;
            now = start;
            continue;
        }
        
        count++;
        now++;
    }
    
    return m;
}
