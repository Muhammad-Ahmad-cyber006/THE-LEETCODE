var expect = function(val) {
    return {
        
        toBe: function(v) {
            if (val === v) {
                return true;
            }
            throw new Error("Not Equal");
        },

        notToBe: function(v) {
            if (val !== v) {
                return true;
            }
            throw new Error("Equal");
        }
    };
};