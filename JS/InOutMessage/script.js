//Get elements
const container = document.querySelector('.container');
const message = document.querySelector('.message');

//Add faceinout class to element we want to activate de message
container.addEventListener('click', () =>{
    message.classList.add('faceinout');
})

//Remove faceinout class when animation ends
message.addEventListener('animationend', () => {
    message.classList.remove('faceinout');
})