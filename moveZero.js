/*
   MoveZero takes an array and moves all zeroes to the end of an array
*/


function swap(array, index1, index2){
  var temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}
function move(zeroes){
    var index = 0;
    var end = zeroes.length - 1;
    while (end > index){
      if(zeroes[index] == 0){
        swap(zeroes, index, end--);
        if(zeroes[index] != 0){
          index++;
        }
      } else {
        index++;
      }
    }
    return zeroes;
}

var array1 = [1,3,9,0,5,4,0,0,6,6,0,2,4,1,0,4,9,7,0,0,1,2,0];
var array2 = [0,0,0,0,0,0,0,0,0,0,0,0,1];
var array3 = [0,1,0,1,0,2,0,3,0,4,0,5,0,6];
var array4 = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,0];

console.log("Moving zeroes: ");
console.log("Array 1: " + array1);
console.log("After moving zeroes: " + move(array1) + "\n");

console.log("Array 1: " + array2);
console.log("After moving zeroes: " + move(array2) + "\n");

console.log("Array 1: " + array3);
console.log("After moving zeroes: " + move(array3) + "\n");

console.log("Array 1: " + array4);
console.log("After moving zeroes: " + move(array4) + "\n");
