document.querySelectorAll(".buttonCenter").forEach(button => {
    button.addEventListener("click", function(){
        if (document.getElementById(button.parentNode.id).classList.contains('spin')) {
            document.getElementById(button.parentNode.id).classList.add('spin2');
            document.getElementById(button.parentNode.id).classList.remove('spin');
            document.querySelectorAll("#" + button.parentNode.id + " .hiddeable").forEach(button => {
                button.classList.add('opacity2');
                button.classList.remove('opacity');
            })
        }else{
            document.getElementById(button.parentNode.id).classList.add('spin');
            document.getElementById(button.parentNode.id).classList.remove('spin2');
            document.querySelectorAll("#" + button.parentNode.id + " .hiddeable").forEach(button => {
                button.classList.add('opacity');
                button.classList.remove('opacity2');
            })
        }
    })
})