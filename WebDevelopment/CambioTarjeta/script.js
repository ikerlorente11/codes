var CONTADOR = 0
document.getElementById('content').innerHTML = '<div id="before" class="before">hola</div>' + CONTADOR

document.getElementById('btn-prev').addEventListener('click', function(){
    CONTADOR--
    document.getElementById('before').innerHTML = CONTADOR
    document.getElementById('content').classList.remove('next')
    document.getElementById('content').classList.add('prev')
    document.getElementById('content').classList.add('selected')
    setTimeout(sigue, 500)
})
document.getElementById('btn-next').addEventListener('click', function(){
    CONTADOR++
    document.getElementById('before').innerHTML = CONTADOR
    document.getElementById('content').classList.remove('prev')
    document.getElementById('content').classList.add('next')
    document.getElementById('content').classList.add('selected')
    setTimeout(sigue, 500)
})

function sigue(){
    document.getElementById('content').classList.remove('selected')
    document.getElementById('content').innerHTML = '<div id="before" class="before">hola</div>' + CONTADOR
}