class Solution {
    public boolean containsDuplicate(int[] nums) {
        // hash set is created to store the seen number
        HashSet<Integer> seen =new HashSet<>();
        //this loop will iterate through every elemnts in nums
        for(int num:nums)// num mei nums ke elemnets jati
        {
            if(seen.contains(num))// agar hash mei so element ah raha ha wo phele se hi exist kr rah ha in hash then it is dupli
             return true; // dupli is found

        seen.add(num); //agar ye number phele seen nahi ha tu seen mei is ki entry
        }
        return false;// no dupli

        
    }

}