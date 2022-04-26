document.querySelectorAll(".menu_icon").forEach(element => {
    element.addEventListener('click', function() {
        if(document.documentElement.clientWidth > 992){
            document.getElementById("body").classList.toggle("body_close")
            document.getElementById("menu").classList.toggle("menu_close")
            document.querySelectorAll(".menu_icon_out")[0].classList.toggle("d-visible")
        }else{
            document.getElementById("menu").classList.toggle("menu_open")
            document.getElementById("body").classList.remove("body_close")
            document.getElementById("menu").classList.remove("menu_close")
            document.querySelectorAll(".menu_icon_out")[0].classList.remove("d-visible")
        }
    })
})