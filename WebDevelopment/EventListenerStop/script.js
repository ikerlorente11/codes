//Get elements
const grandparent = document.querySelector(".grandparent")
const parent = document.querySelector(".parent")
const child = document.querySelector(".child")

//Set click event listener to grandparent
grandparent.addEventListener('click', e => {
    console.log("I'm the grandparent")
})

//Set click event listener to parent
//Set stop propagation to not execute grandparent listener on clicking in the parent or the child
parent.addEventListener('click', e => {
    e.stopPropagation()
    console.log("I'm the parent")
})

//Set click event listener to child
child.addEventListener('click', e => {
    console.log("I'm the child")
})