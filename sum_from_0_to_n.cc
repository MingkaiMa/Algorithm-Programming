#include <iostream>
#include <string>

using namespace std;



class SequenceSum{
  int count;
  public:
  SequenceSum (int);
  string showSequence();

};

string SequenceSum::showSequence(){
  string result = "";

  if(count == 0){

    return "0=0";

  }
  if(count < 0){

    return to_string(count) + string("<0");
  }



  int sum_ = 0;
  for(int i = 0; i <= count; i++){

    result += std::to_string(i);
    sum_ += i;
    if(i != count){
      result += string("+");
    }
  }
  result += string(" = ");
  result += to_string(sum_);

  return result;

}

SequenceSum::SequenceSum (int c) {
  count = c;
}


int main(){

    string result = "";
    int sum = 0;
    for(int i = 0; i <= 6; i++){
        result += to_string(i);
        sum += i;
        if(i != 6){
            result += string("+");
        }

    }

    result += string(" = ");
    result += to_string(sum);
    cout << result << endl;

    int n = -15;
    string R = "";
    R += to_string(n);
    R += string("<0");
    R += "\nI am happy";
    cout << R << endl;


}