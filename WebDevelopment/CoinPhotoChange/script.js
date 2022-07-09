//Coin images
images = ['flash.jpeg','jay.jpg','iris.jpeg','jesse.jpg','liberty.jpg']
//Image change speed
delay = 350
//Auto image change timer
timer = ""

document.querySelectorAll(".coin").forEach(element => {
    element.setAttribute("style", "--time: "+ delay / 1000 +"s")

    element.firstElementChild.addEventListener("click", function(){
        //*Uncomment to enable auto image change
        //clearInterval(timer)
        changeImage(element, false)
        //*Uncomment to enable auto image change
        //timer = setInterval(changeImage, 5000, element, true)
    })
    element.lastElementChild.addEventListener("click", function(){
        //*Uncomment to enable auto image change
        //clearInterval(timer)
        changeImage(element, true)
        //*Uncomment to enable auto image change
        //timer = setInterval(changeImage, 5000, element, true)
    })

    //*Uncomment to enable auto image change
    //timer = setInterval(changeImage, 5000, element, true)
})

/**
 * Changes the image of the element selected
 * @param {Object} element Coin to change image
 * @param {Boolean} forward Forward or backward change
 */
function changeImage(element, forward){
    //Hide coin
    element.classList.toggle('rotateA')
    element.classList.toggle('rotateB')

    //Set orientation
    if(forward){
        images.push(images.shift())
    }else{
        images.unshift(images.pop())
    }

    //Change image and show coin
    setTimeout(() => {
        //Change image
        element.querySelectorAll("img")[0].src = 'images/' + images[0]
        //Show image
        element.classList.toggle('rotateA')
        element.classList.toggle('rotateB')
    }, delay)
}