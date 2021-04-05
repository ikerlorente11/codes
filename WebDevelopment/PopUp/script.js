const openModalButtons = document.querySelectorAll('[data-modal-target]');
const closeModalButtons = document.querySelectorAll('[data-close-button]');
const overlay = document.getElementById('overlay');

openModalButtons.forEach(button => {
    button.addEventListener('click', () =>{
        //Get the element with the id of the target we define
        const modal = document.querySelector(button.dataset.modalTarget)
        //Shows selected element
        openModal(modal)
    })
})

overlay.addEventListener('click', () => {
    //Get elements with the class modal and active
    const modals = document.querySelectorAll('.modal.active')
    modals.forEach(modal => {
        //Hide selected elements
        closeModal(modal)
    })
})

closeModalButtons.forEach(button => {
    button.addEventListener('click', () =>{
        //Get the closest element with the class modal above clicked button
        const modal = button.closest('.modal')
        //Hide selected element
        closeModal(modal)
    })
})

/**
 * Shows the PopUp
 * 
 * @param {Element} modal The container we want to show
 * @returns If modal is null it returns nothing
 */
function openModal(modal){
    if(modal == null) return
    modal.classList.add('active')
    overlay.classList.add('active')
}

/**
 * Hides the PopUp
 * 
 * @param {Element} modal The container we want to hide
 * @returns If modal is null it returns nothing
 */
function closeModal(modal){
    if(modal == null) return
    modal.classList.remove('active')
    overlay.classList.remove('active')
}