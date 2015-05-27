/*maxGain.js*/
/*
    Given an array of timestamps and values (in sorted order),
    return the max gain from some timestamp ti to tj
    *tj > ti
    *gain from ti to tj does not have to include timestamps in between
    *smallest possible gain = 0

    [{time: timestamp1, value: 1},
     {time: timestamp2, value: 2}]

*/
//keep track of smallest number SO FAR; 
//keep track of greatest gain SO FAR

//check if current value is greater than min
//maxGain, currentGain, current Value - min

var timestamps = [
  {time: "t1", value: 1},
  {time: "t1", value: 2},
  {time: "t1", value: 1},
  {time: "t1", value: 5},
  {time: "t2", value: -2},
  {time: "t2", value: 4},
  {time: "t2", value: 2},
  {time: "t2", value: 4},
  {time: "t2", value: 3}
];

function maxGain(timeValues){
  var min = timeValues[0].value;
  var gain = 0;
  for(var i = 1; i < timeValues.length; i++){
      var currentValue = timeValues[i].value;
      if(currentValue <= min){
        min = currentValue;
        continue;
      }
      //check gain from previous index
      var currentGain = currentValue - min;
      //compare gain with max gain
      if(currentGain > gain){
        gain = currentGain;
      }
  }
  return gain;
}

console.log(maxGain(timestamps));

