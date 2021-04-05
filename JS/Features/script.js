//NULLISH

/*
//Normal
function calculatePrice(price, taxes, description) {
    taxes = taxes || .05
    description = description || "Default item"
    const total = price * (1 + taxes)
    console.log(`${description} With Tax: $${total}`)
}
*/

//Nullish coalescing
function calculatePrice(price, taxes, description) {
    taxes = taxes ?? .05
    description = description ?? "Default item"
    const total = price * (1 + taxes)
    console.log(`${description} With Tax: $${total}`)
}

calculatePrice(100, 0.07, "My item")
calculatePrice(100, 0, "My other item")
calculatePrice(100, undefined, "")


//STYLE CONSOLE LOG
console.log('This is a normal console log')
console.log('This is a %cstyled%c console log', "font-weight: bold; color: red", "color: green")


//OPTIONAL CHAINING
class Person{
    constructor(name, address, hobbies){
        this.name = name
        this.address = address
        this.hobbies = hobbies
    }

    print(){
        console.log(this)
    }
}

/*
//Normal
function printPersonStreet(person){
    console.log(person && person.address && person.address.street)
}
*/

//Optional chaining
function printPersonStreet(person){
    console.log(person?.address?.street)
}

const kyle = new Person(
    "Kyle",
    {street: "12345 main st", city: "Somewhere"},
    ["Bowling", "Weight Lifting"]
)
kyle.print()
printPersonStreet(kyle)

const mike = new Person(
    "Mike",
    undefined
)
mike.print()
mike.printName?.()
printPersonStreet(undefined)

console.log(mike.hobbies?.[0])
console.log(kyle.hobbies?.[0].toLowerCase())


//OBJECT SHORTHAND
const name = 'John'
const favoriteFood = 'rice'

const john = {
    name,
    food: favoriteFood
}

console.log(john)