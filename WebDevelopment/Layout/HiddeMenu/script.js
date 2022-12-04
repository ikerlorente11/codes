if(screen.width <= 992){
    document.getElementById('structure').classList.remove('menu-open')
}

document.getElementById('menu-icon').addEventListener('click', function(){
    document.getElementById('structure').classList.toggle('menu-open')
})
document.getElementById('settings-icon').addEventListener('click', function(){
    document.getElementById('structure').classList.toggle('settings-open')
})