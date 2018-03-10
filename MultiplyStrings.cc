class Solution {
public:
    string multiply(string num1, string num2) {

        long int len1 = num1.length();
        long int len2 = num2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param
        vector<int> res(len1 + len2);
        for(int i = 0; i < len1 + len2; i++){
            res[i] = 0;
        }

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == num1.size()){
                op1[i] = num1[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = num1[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == num2.size()){
                op2[i] = num2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = num2[i - count] - '0';
            }
        }

        reverse(op1.begin(), op1.end());
        reverse(op2.begin(), op2.end());


//        for(int i = 0; i < n_size; i++){
//            cout << op1[i];
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i];
//        }
//
//        cout << "\n";

        //int carry = 0;

        for(int i = 0; i < n_size; i++){
            for(int j = 0; j < n_size; j++){
                res[i + j] = res[i + j] + op1[i] * op2[j];
            }
        }


//        cout << "=====\n";
//        for(int i = 0; i < res.size(); i++){
//            cout << res[i] << ", ";
//        }

//        cout << "\n===" << res.size() << "\n";
//


        int carry = 0;
        for(int i = 0; i < res.size(); i++){
            int rr =res[i];
            res[i] = (res[i] + carry) % 10;
            //cout << "res is: " << res[i] << "\n";
            carry = (rr + carry) / 10;
            //cout << "carry is: " << carry << "\n";
        }

//        for(int i = 0; i < res.size(); i++){
//            cout << res[i] << ", ";
//        }
//        cout << "\nabove\n";

        reverse(res.begin(), res.end());

        int flag = 1;
        string R;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == 0 && flag == 1){
                continue;
            }
            else{
                R += to_string(res[i]);
                flag = 0;
            }
        }

        if(R.length() == 0){

            return "0";
        }

        //string R = to_string(res[0]);
        //cout << R << "\n";

        return R;

    }
};