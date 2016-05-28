#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> ret;
    void findTwoSum(vector<int> &source, int target) {
        for (int i = 0; i < source.size() - 1; ++i) {
            for (int j = i + 1; j < source.size(); ++j) {
                if (source[i] + source[j] == target) {
                    ret.push_back(source[i]);
                    ret.push_back(source[j]);
                }
            }
        }
    }
    void findSum(int *s,int n,int x)
    {
        //sort(s,s+n);   如果数组非有序的，那就事先排好序O（N*logN）

        int *begin=s;
        int *end=s+n-1;

        while(begin<end)    //俩头夹逼，或称两个指针两端扫描法，很经典的方法，O（N）
        {
            if(*begin+*end>x)
            {
                --end;
            }
            else if(*begin+*end<x)
            {
                ++begin;
            }
            else
            {
                ret.push_back(*begin);
                ret.push_back(*end);
                return;
            }
        }
    }

    void test(){
        unsigned int a = 5;
        unsigned int *pint = NULL;
        cout << "&a" << &a << endl << " a="<<a << endl;
        cout << "&pint" << &pint << endl << " pint="<< pint << endl;
        cout << "&(*pint)" << &(*pint) << endl << endl;
        cout << "*(&pint)" << *(&pint) << endl << endl;

        pint = &a;
        cout << "&a" << &a << endl << " a="<<a << endl;
        cout << "&pint" << &pint << endl << " pint="<< pint << endl;
        cout << "&(*pint)" << &(*pint) << endl << endl;
        cout << "*(&pint)" << *(&pint) << endl << endl;

        *pint = 10;
        cout << "&a" << &a << endl << " a="<<a << endl;
        cout << "&pint" << &pint << endl << " pint="<< pint << endl;
        cout << "&(*pint)" << &(*pint) << endl << endl;
        cout << "*(&pint)" << *(&pint) << endl << endl;
    }

};

int main() {
    Solution s;
    vector<int> source = {1, 2, 4, 6, 13, 24, 56};
    //s.findTwoSum(source, 57);
    s.findSum(source.data(), source.size(), 57);
    for (int i = 0; i < s.ret.size(); ++i) {
        cout << s.ret[i] << endl;
    }
    s.test();
    return 0;
}