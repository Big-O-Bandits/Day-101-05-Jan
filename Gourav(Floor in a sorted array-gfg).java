class Solution {
    public int[] getFloorAndCeil(int x, int[] arr) {
        // code here
        Arrays.sort(arr);
        int[]res=new int[2];
        res[0]=getfloor(arr,x);
        res[1]=getceil(arr,x);
        return res;
        
    }
    private int getfloor(int[]arr,int x){
        int low=0;
        int high=arr.length-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=x){
                ans=arr[mid];
                low=mid+1;
            }else if(arr[mid]>x){
                high=mid-1;
            }
        }
        return ans;
        
    }
    private int getceil(int[] arr, int x){
        
        int low=0;
        int high=arr.length-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                ans=arr[mid];
                high=mid-1;
            }else if(arr[mid]<x){
                low=mid+1;
            }
        }
        return ans;
    }
}
