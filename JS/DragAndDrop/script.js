//Elements we want to move and teh containers in where we want to put
const draggables = document.querySelectorAll('.draggable')
const containers = document.querySelectorAll('.container')

//Adding event listeners to items on dragging start and dragging end
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
		//Cancel event if it is cancelable
		e.preventDefault()

		//Get the closest item to the cursor
		const afterElement = getDragAfterElement(container, e.clientX, e.clientY)
		//const afterElement = getDragAfterElementHorizontally(container, e.clientX)
		//const afterElement = getDragAfterElementVertically(container, e.clientY)

		//Get dragging item
		const draggable = document.querySelector('.dragging')

		//Insert dragging item on the end or before closest item
		if(afterElement == null){
			container.appendChild(draggable)
		}else{
			container.insertBefore(draggable, afterElement)
		}		
	})
})

/**
 * Returns the closest element to the position of the cursor
 * 
 * @param {Element} container The container where we want to put the item
 * @param {number} x X position of the cursor
 * @param {number} y Y position of the cursor
 * @returns Closest element to the position of the cursor
 */
function getDragAfterElement(container, x, y){
	//Get draggable items
	const draggableElements = [...container.querySelectorAll('.draggable:not(.dragging)')]

	//Compare all items to find the closest
	return draggableElements.reduce((closest, child) => {
		//Get box points
		const box = child.getBoundingClientRect()

		//Set limit to half width of the items and top height
		const offsetX = x - box.left - box.width / 2
		const offsetY = y - box.top

		//If find a closest one return it, else return previous
		if((offsetX < 0 && offsetX > closest.offset.offsetX) || (offsetY < 0 && offsetY > closest.offset.offsetY)){
			return { offset: {offsetX: offsetX, offsetY: offsetY}, element: child }
		}else{
			return closest
		}

		//Start in negative infinite number
	}, {offset: {offsetX: Number.NEGATIVE_INFINITY, offsetY: Number.NEGATIVE_INFINITY}}).element
}

/**
 * Returns the closest element to the position of the cursor horizontally
 * 
 * @param {Element} container The container where we want to put the item
 * @param {number} x X position of the cursor
 * @returns Closest element to the position of the cursor horizontally
 */
function getDragAfterElementHorizontally(container, x){
	//Get draggable items
	const draggableElements = [...container.querySelectorAll('.draggable:not(.dragging)')]

	//Compare all items to find the closest
	return draggableElements.reduce((closest, child) => {
		//Get box points
		const box = child.getBoundingClientRect()

		//Set limit to half width of the items and top height
		const offset = x - box.left - box.width / 2

		//If find a closest one return it, else return previous
		if(offset < 0 && offset > closest.offset){
			return { offset: offset, element: child }
		}else{
			return closest
		}

		//Start in negative infinite number
	}, {offset: Number.NEGATIVE_INFINITY}).element
}

/**
 * Returns the closest element to the position of the cursor vertically
 * 
 * @param {Element} container The container where we want to put the item
 * @param {number} y Y position of the cursor
 * @returns Closest element to the position of the cursor vertically
 */
function getDragAfterElementVertically(container, y){
	//Get draggable items
	const draggableElements = [...container.querySelectorAll('.draggable:not(.dragging)')]

	//Compare all items to find the closest
	return draggableElements.reduce((closest, child) => {
		//Get box points
		const box = child.getBoundingClientRect()

		//Set limit to half width of the items and top height
		const offset = y - box.top - box.height / 2

		//If find a closest one return it, else return previous
		if(offset < 0 && offset > closest.offset){
			return { offset: offset, element: child }
		}else{
			return closest
		}

		//Start in negative infinite number
	}, {offset: Number.NEGATIVE_INFINITY}).element
}