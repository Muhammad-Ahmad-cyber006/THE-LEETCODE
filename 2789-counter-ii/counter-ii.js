/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let initCount=init
    function increment(){
        return ++initCount;
    }
    function decrement(){
        return --initCount
    }
    function reset()
    {
        initCount=init;
        return initCount;
    }
    return{
        increment: increment,
        decrement: decrement,
        reset: reset
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */