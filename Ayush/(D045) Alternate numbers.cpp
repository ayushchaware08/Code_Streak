// link: https://www.naukri.com/code360/problems/alternate-numbers_6783445 
// TC=o(2N)
vector<int> alternateNumbers(vector<int>&a) {
    vector<int> neg, pos;
    int n= a.size();
    
    // seperation
    for(int i=0; i<n; i++){
        if(a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    if(pos.size()>neg.size()){
        // insertion pos==neg
        for(int i=0; i<neg.size(); i++){ // neg is  small
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        // remaining insertion
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size();i++){
            a[index] = pos[i];
            index++;
        }
    }
    else{
        // insertion pos==neg
        for(int i=0; i<pos.size(); i++){ // neg is  small
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        // remaining insertion
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size();i++){
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}