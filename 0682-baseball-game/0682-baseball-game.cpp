class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;

        for (string op : operations){
            if(op != "C" && op != "D" && op != "+"){
                st.push(stoi(op));
            }
            else if( op == "C"){
                st.pop();
            }
            else if(op == "D"){
                int x = st.top() *2;
                st.push(x);
            }
            else if( op == "+"){
                int a = st.top();
                st.pop();

                int b = st.top();
                  
                st.push(a);
                st.push(a+b);
            }


        }
        int sum =0;
        while (!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum ;
        
    }
};