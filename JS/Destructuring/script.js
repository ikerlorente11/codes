/*
//Destructuring arrays
const alphabet = ['A','B','C','D','E','F']
const numbers = ['1','2','3','4','5','6']

//Typical method
// const a = alphabet[0]
// const b = alphabet[1]

//Destructuriong method
const [a,, c, ...rest] = alphabet
const newArray = [...alphabet, ...numbers]

console.log(a)
console.log(c)
console.log(rest)
console.log(newArray)

//Using destructuring to use multiple returns of a function
function sumAndMultiply(a, b){
    return [a+b, a*b, a/b]
}

const [sum, multiply, division = 'No division'] = sumAndMultiply(2, 3)
console.log(sum)
console.log(multiply)
console.log(division)
*/

//----------------------------------------------------------------

const personOne = {
    name: 'Iker',
    age: 23,
    favoriteFood: 'Macarrons',
    address: {
        city: 'Vitoria',
        provincia: 'Alava'
    }
}

const personTwo = {
    age: 24,
    favoriteFood: 'Watermelon',
}

/*
//Using destructuring to get object parameters
const { name, address} = personOne
console.log(name)
console.log(address)
*/

/*
//Getting attribute from objet with different name
const { name: firstname, age, favoriteFood = 'Rice'} = personOne
console.log(firstname)
console.log(age)
console.log(favoriteFood)
*/

/*
//Getting the rest of the object
const { name: firstname, ...rest} = personOne
console.log(firstname)
console.log(rest)
*/

/*
//Destructuring object parameters on destructuration
const { name: firstname, address: { city }} = personOne
console.log(firstname)
console.log(city)
*/

/*
//Combining objects
const personThree = {...personOne, ...personTwo}
console.log(personThree)
*/

//Using destructuring objects in functions
function printUser({ name, age, favoriteFood = 'Watermelon'}){
    console.log(`Name is ${name}. Age is ${age}. FavoriteFood is ${favoriteFood}`)
}

printUser(personOne)