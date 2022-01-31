console.log("This is tutorial for JavaScript");

function greet(name, greetText="Greetings from JavaScipt"){
    let name1 = "Name1"; // local scope variable
    console.log(greetText + " " + name);
    console.log(name + " is a good boy");
}

function sum(a, b, c){
    let d = a + b + c ;
    return d;
    // This line will never execute (Unreachable Code)
    // console.log("Function is returned");
}


let name = "Coder";
let name1 = "Developer"; // global scope variable
let name2 = "Hacker"; 
let name3 = "programmer";
let GreetText1 = "Good Morning";
// console.log(name + " is a good boy");
// console.log(name1 + " is a good boy");
// console.log(name2 + " is a good boy");
// console.log(name3 + " is a good boy");

greet(name, GreetText1);
greet(name1, GreetText1);

greet(name2);

// let returnVal = greet(name3);
// console.log(returnVal)

let returnVal = sum(1,2,3);
console.log(returnVal);