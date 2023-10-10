document.querySelector('i.top-left').addEventListener('click', () => {
    document.querySelector('.menu.top.left').classList.toggle('open')
})
document.querySelector('i.top-right').addEventListener('click', () => {
    document.querySelector('.menu.top.right').classList.toggle('open')
})
document.querySelector('i.bottom-left').addEventListener('click', () => {
    document.querySelector('.menu.bottom.left').classList.toggle('open')
})
document.querySelector('i.bottom-right').addEventListener('click', () => {
    document.querySelector('.menu.bottom.right').classList.toggle('open')
})