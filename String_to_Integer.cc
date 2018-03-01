#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){

    string s = "   -00123456a42r3";
    std::regex plus ("^ *([+]?)([0-9]+).*");
    std::regex minus ("^ *(-?)([0-9]+).*");
    std::smatch matches;

    if(std::regex_search(s, matches, plus)){

        cout << "plus here\n";
//        cout << matches.size() << "\n";
//        for(int i = 1; i < matches.size(); i++){
//            cout << matches[i].str() << "\n";
//        }
//
//
//        cout << "\n";
//        cout << matches[2].str() << "\n";
        string max_int = "2147483647";
        string ss_plus = matches[2].str();
        cout << ss_plus << "\n";
        cout << max_int.length() << ", " << ss_plus.length() << "\n";
        if(max_int.length() == ss_plus.length()){
            for(int i = 0; i < max_int.length(); i++){
                if(max_int[i] == ss_plus[i]){
                    continue;
                }
                else if((ss_plus[i] - '0') < (max_int[i] - '0')){
                    return stoi(ss_plus);
                }
                else if((ss_plus[i] - '0') > (max_int[i] - '0')){
                    return INT_MAX;
                }
            }
            return stoi(ss_plus);
        }

        else if(max_int.length() < ss_plus.length()){
            return INT_MAX;
        }
        else{

            return stoi(ss_plus);
        }


    }

    else if(std::regex_search(s, matches, minus)){

        cout << "minus here\n";
        cout << matches.size() << "\n";
        for(int i = 1; i < matches.size(); i++){
            cout << matches[i].str() << "\n";
        }

        string ss_plus = matches[2].str();
        string max_int = "2147483648";

        if(max_int.length() == ss_plus.length()){
            for(int i = 0; i < max_int.length(); i++){
                if(max_int[i] == ss_plus[i]){
                    continue;
                }
                else if((ss_plus[i] - '0') < (max_int[i] - '0')){
                    string r;
                    r += matches[1].str();
                    r += ss_plus
                    return stoi(r);
                }
                else if((ss_plus[i] - '0') > (max_int[i] - '0')){
                    return INT_MIN;
                }
            }
            string r;
            r += matches[1].str();
            r += ss_plus
            return stoi(r);
        }

        else if(max_int.length() < ss_plus.length()){
            return INT_MIN;
        }
        else{

            string r;
            r += matches[1].str();
            r += ss_plus
            return stoi(r);
        }
    }
//
//
//        cout << "\n";
//        cout << matches[2].str() << "\n";
//        string max_int = "2147483647";
//        string ss_plus = matches[2].str();
//        cout << ss_plus << "\n";
//        cout << max_int.length() << ", " << ss_plus.length() << "\n";
//        if(max_int.length() == ss_plus.length()){
//            for(int i = 0; i < max_int.length(); i++){
//                if(max_int[i] == ss_plus[i]){
//                    continue;
//                }
//                else if((ss_plus[i] - '0') < (max_int[i] - '0')){
//                    return stoi(ss_plus);
//                }
//                else if((ss_plus[i] - '0') > (max_int[i] - '0')){
//                    return INT_MAX;
//                }
//            }
//            return stoi(ss_plus);
//        }
//
//        else if(max_int.length() < ss_plus.length()){
//            return INT_MAX;
//        }
//        else{
//
//            return stoi(ss_plus);
//        }
//
//
//    }



//    if(std::regex_match(s, plus)){
//        cout << "Matched\n";
//
//        std::regex plus_more("[0-9]+");
//        std::smatch plus_s;
//        std::regex_search(s, plus_s, plus_more);
//        for (auto x: plus_s) std::cout << x << ",\n";
//
//        cout << "*****\n";
//        cout << plus_s.str() << "\n";
//        string ss_plus = plus_s.str();
//        string max_int = "2147483647";
//
//        if(max_int.length() == ss_plus.length()){
//            for(int i = 0; i < max_int.length(); i++){
//                if(max_int[i] == ss_plus[i]){
//                    continue;
//                }
//                else if((ss_plus[i] - '0') < (max_int[i] - '0')){
//                    return stoi(ss_plus);
//                }
//                else if((ss_plus[i] - '0') > (max_int[i] - '0')){
//                    return INT_MAX;
//                }
//            }
//            return stoi(ss_plus);
//        }
//
//        else if(max_int.length() < ss_plus.length()){
//            return INT_MAX;
//        }
//        else{
//            return stoi(ss_plus);
//        }
//
//    }
//
//
//    else if(std::regex_match(s, minus)){
//        cout << "Matched minues\n";
//
//        std::regex plus_more("-[0-9]+");
//        std::smatch plus_s;
//        std::regex_search(s, plus_s, plus_more);
//        for (auto x: plus_s) std::cout << x << ",\n";
//
//        cout << "*****\n";
//        cout << plus_s.str() << "\n";
//        string ss_plus = plus_s.str();
//        string max_int = "2147483648";
//
//        if(max_int.length() == ss_plus.length()){
//            for(int i = 0; i < max_int.length(); i++){
//                if(max_int[i] == ss_plus[i]){
//                    continue;
//                }
//                else if((ss_plus[i] - '0') < (max_int[i] - '0')){
//                    return stoi(ss_plus);
//                }
//                else if((ss_plus[i] - '0') > (max_int[i] - '0')){
//                    return INT_MAX;
//                }
//            }
//            return stoi(ss_plus);
//        }
//
//        else if(max_int.length() < ss_plus.length()){
//            return INT_MAX;
//        }
//        else{
//            return stoi(ss_plus);
//        }
//
//    }
//    else{
//        return 0;
//    }

//
//    string s = "2147483648";
//    cout << stoi(s) << "\n";


}