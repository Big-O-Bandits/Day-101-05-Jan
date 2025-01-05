class Solution {
    int countFreq(int[] arr, int target) {
        // code here
        int first=findfirst(arr,target);
        if(first==-1){
            return 0;
        }
        int last=findlast(arr,target);
        return last-first+1;
        
    }
    private int findfirst(int[]arr,int target){
        int low=0;
        int high=arr.length-1;
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                result=mid;
                high=mid-1;
            }else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return result;
    }
    private int findlast(int[]arr,int target){
        int low=0;
        int high=arr.length-1;
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                result=mid;
                low=mid+1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
}
