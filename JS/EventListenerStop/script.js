const grandparent = document.querySelector(".grandparent")
const parent = document.querySelector(".parent")
const child = document.querySelector(".child")

grandparent.addEventListener('click', e => {
    e.stopPropagation()
    console.log("I'm the grandparent")
})

parent.addEventListener('click', e => {
    e.stopPropagation()
    console.log("I'm the parent")
})

child.addEventListener('click', e => {
    e.stopPropagation()
    console.log("I'm the child")
})