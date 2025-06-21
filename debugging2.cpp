/*
 Topics: Debug

 Instructions: Output highest of three inputs.

 #include <iostream>
 using namespace std;

 int main() {
     float n1 n2 n3,

     cout << "Enter three numbers: ";
     cin >> n1 > n1 > n3;

 if(n1 = n2 && n1 >= n3
         cout << "Largest number: " << n1;

     if(n2 == n1 && n2 >= n3)
    {     cout << "Largest number: " << n1;

     if(n3 >= n1 && n3 >= n2)
         cout << "Largest number: " << n2
   }
     return 0;
 }
 */

#include <iostream>
using namespace std;

void max(float n1, float n2, float n3) {

    float max = n1;

    if (n2 > n1 && n2 >= n3)
        max = n2;

    else if (n3 > n1 && n3 >= n2)
        max = n3;

    cout << "*** Largest number: " << max << " ***\n" << endl;
}

int main() {
    
    float n1, n2, n3;

    cout << "\t- Enter three numbers -" << endl;

    cout << "\n1st number: ";
    cin >> n1;
    cout << endl;

    cout << "2nd number: ";
    cin >> n2;
    cout << endl;

    cout << "3rd number: ";
    cin >> n3;
    cout << endl;

    max(n1, n2, n3);

    return 0;
}
