#include <iostream>
#include <vector>

using namespace std;

bool can_cross(float p, int a, int b, vector<float> &k,int i,int m){
    if(i>=11){
        return true;
    }
    if(p < k[i] && a <= 0 && b <= 0){
        return false;
    }
    if(p >= k[i]){
        return can_cross(p-k[i],a,b,k,i+1,m);
    }
    else{
        bool t = 0;
        bool l = 0;
        if(a > 0)
            t = can_cross(p,a-1,b,k,i+1,m);
        if(b > 0)
            l = can_cross(m,a,b-1,k,i+1,m);
        return (t || l);
    }
    
}


bool can_cross_chakravyuha(float p, int a, int b, vector<float> k) {
    float m = p;
    k[3] = k[3] + k[2]/2;
    k[7] = k[7] + k[6]/2;
    
    return can_cross(p,a,b,k,0,m);
}

int main() {
    // Test Case 1
    float p1 = 16;
    int a1 = 2;
    int b1 = 3;
    vector<float> k1 = {5, 6, 4, 7, 3, 8, 9, 2, 1, 10, 11};

    if (can_cross_chakravyuha(p1, a1, b1, k1)) {
        cout << "Abhimanyu can cross the Chakravyuha in Test Case 1." << endl;
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuha in Test Case 1." << endl;
    }

    // Test Case 2
    float p2 = 15;
    int a2 = 0;
    int b2 = 2;
    vector<float> k2 = {6, 7, 5, 8, 4, 9, 10, 3, 2, 12, 13};

    if (can_cross_chakravyuha(p2, a2, b2, k2)) {
        cout << "Abhimanyu can cross the Chakravyuha in Test Case 2." << endl;
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuha in Test Case 2." << endl;
    }

    return 0;
}
