const draggables = document.querySelectorAll('.draggable')
const containers = document.querySelectorAll('.container')

draggables.forEach(draggable => {
	draggable.addEventListener('dragstart', () => {
		draggable.classList.add('dragging')
	})

	draggable.addEventListener('dragend', () => {
		draggable.classList.remove('dragging')
	})
})

containers.forEach(container => {
	container.addEventListener('dragover', e => {
		e.preventDefault()
		const afterElement = getDragAfterElement(container, e.clientX, e.clientY)
		const draggable = document.querySelector('.dragging')
		if(afterElement == null){
			container.appendChild(draggable)
		}else{
			container.insertBefore(draggable, afterElement)
		}		
	})
})

function getDragAfterElement(container, x, y){
	const draggableElements = [...container.querySelectorAll('.draggable:not(.dragging)')]

	return draggableElements.reduce((closest, child) => {
		const box = child.getBoundingClientRect()
		const offsetX = x - box.left - box.width / 2
		const offsetY = y - box.top
		console.log(closest.offset.offsetX)
		if((offsetX < 0 && offsetX > closest.offset.offsetX) || (offsetY < 0 && offsetY > closest.offset.offsetY)){
			return { offset: {offsetX: offsetX, offsetY: offsetY}, element: child }
		}else{
			return closest
		}
	}, {offset: {offsetX: Number.NEGATIVE_INFINITY, offsetY: Number.NEGATIVE_INFINITY}}).element
}