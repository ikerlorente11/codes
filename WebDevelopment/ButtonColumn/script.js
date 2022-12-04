document.querySelectorAll(".main").forEach(element => {
    element.addEventListener("click", function(){
        element.parentElement.querySelectorAll("i").forEach(element => {
            element.classList.toggle("selected")
        })
    })
})

document.querySelectorAll("i:not(.main)").forEach(element => {
    element.addEventListener("click", function(){
        console.log(element.querySelector("p").getAttribute("value"))
    })
})