//Get elements
const container = document.querySelector('.container');
const messages = document.querySelectorAll('.message');

//Add faceinout class to elements we want to activate de message
container.addEventListener('click', () =>{
    messages.forEach(message => {
        message.classList.add('faceinout');
    })
})

//Remove faceinout class when animation ends
messages.forEach(message => {
    message.addEventListener('animationend', () => {
        message.classList.remove('faceinout');
    })
})