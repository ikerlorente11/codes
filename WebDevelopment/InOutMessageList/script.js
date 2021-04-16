//Get elements
const container = document.querySelector('.container');
const message_list = document.querySelector('.message-list');

//Add faceinout class to elements we want to activate de message
container.addEventListener('click', () =>{
    //Create message element
    const message = document.createElement('div');
    message.classList.add('message');
    message.classList.add('faceinout');
    message.innerHTML = "This is the message text";

    //Remove faceinout class when animation ends
    message.addEventListener('animationend', () => {
        message.remove();
    })

    //Add message to messages list
    message_list.prepend(message);

    let root = document.documentElement;
    root.style.setProperty('--message-height', "-" + document.querySelector('.message').offsetHeight + "px");

    message_list.classList.remove('uptodown');
    setTimeout(() => {  message_list.classList.add('uptodown'); }, 0);
})