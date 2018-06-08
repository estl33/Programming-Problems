class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double sum = 0;
        double oddMedian = 0;
        double evenMedian = 0;
        int size = nums1.size() + nums2.size(); 
        vector<int> nums12;
        
        nums12.reserve(size);
        nums12.insert( nums12.end(), nums1.begin(), nums1.end() );
        nums12.insert( nums12.end(), nums2.begin(), nums2.end() );
        struct myclass {
            bool operator() (int i,int j) { return (i<j);}
        } myobject;
        sort (nums12.begin(), nums12.end(), myobject);     

        int i = 0;
        for(std::vector<int>::iterator it = nums12.begin(); it != nums12.end(); ++it){
            sum += *it;
              
            if(i == size/2){
                evenMedian = (*(it-1) + *(it)) /2.0;
                oddMedian = *it;
            }
            i++;
        }
        
        if(size % 2 != 0) return oddMedian;
        else return evenMedian;
        
    }
};