//
//  main.cpp
//  test
//
//  Created by TPS on 16/4/2.
//  Copyright © 2016年 TPS. All rights reserved.
//

#include "countBits.cpp"

int main_1(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> m;
    m = countBits(n);
    for (int i = 0; i<m.size(); i++) {
        cout<< m[i] << endl;
    }

    return 0;
}


