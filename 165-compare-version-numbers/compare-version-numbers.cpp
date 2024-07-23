class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, f1 = 0, f2 = 0;
        int n1 = version1.length();
        int n2 = version2.length();
        string v1 = "", v2 = "";
        vector<int> arr1;
        vector<int> arr2;
        while(i < n1)
        {
            if(version1[i] == '.')
            {
                arr1.push_back(stoi(v1));
                i++;
                v1 = "";
            }
            else
            {
                v1 += version1[i];
                i++;
            }
        }
        while(j < n2)
        {
            if(version2[j] == '.')
            {
                arr2.push_back(stoi(v2));
                j++;
                v2 = "";
            }
            else
            {
                v2 += version2[j];
                j++;
            }
        }
        if(v1 != "") arr1.push_back(stoi(v1));
        if(v2 != "") arr2.push_back(stoi(v2));
        f1 = arr1.size();
        f2 = arr2.size();
        while(f1 < f2)
        {
            arr1.push_back(0);
            f1++;
        }
        while(f2 < f1)
        {
            arr2.push_back(0);
            f2++;
        }
        cout<<f1<<f2<<endl;
        for(i=0; i<f1; i++)
        {
            if(arr1[i] > arr2[i])
                return 1;
            else if(arr1[i] < arr2[i])
                return -1;
        }

        return 0;

        // while(i < n1 && j < n2)
        // {
        //     v1 = ""; v2 = "";
        //     while(i < n1 && version1[i] != '.')
        //     {
        //         v1 += version1[i];
        //         i++;
        //     }
        //     while(j < n2 && version2[j] != '.')
        //     {
        //         v2 += version2[j];
        //         j++;
        //     }
        //     i++; j++;
        //     f1 = stoi(v1);
        //     f2 = stoi(v2);
        //     if(f1 > f2) return 1;
        //     else if(f1 < f2) return -1;
        //     cout<<"kkk"<<endl;
        // }
        // v1 = ""; v2 = "";
        // cout<<"UU"<<endl;
        // while(i < n1 && version1[i] != '.')
        // {
        //     v1 += version1[i];
        //     i++;
        // }
        // while(j < n2 && version2[j] != '.')
        // {
        //     v2 += version2[j];
        //     j++;
        // }
        // if(v1 != "") f1 = stoi(v1);
        // else f1 = 0;
        // if(v1 != "") f2 = stoi(v2);
        // else f2 = 0;

        // if(f1 > f2) return 1;
        // else if(f1 < f2) return -1;
        // return 0;
    }
};