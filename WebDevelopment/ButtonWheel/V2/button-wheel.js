/**
 * Generate a button wheel
 * 
 * @param {string} wheel_id The id of the container where you want to generate the button wheel
 * @param {number} position The position where you want to be the button wheel. 0: Center, 1: Bottom left, 2: Top left, 3: Top right, 4: Bottom right
 * @param {array[string]} btn_list A list of the bootstrap icons you what for each button, clockwise, starting from the top
 */
function generate_buttons(wheel_id, position, btn_list){
    let cont = 0
    for(var i = 0; i < btn_list.length; i++){
        const deg = 360 / btn_list.length * i
        let right = Math.sin(Math.PI * (deg/180));
        let bottom = Math.cos(Math.PI * (deg/180));
        if(right < 0.001 && right > 0){ right = 0 }
        if((bottom < 0.001 && bottom > 0) || (bottom > -0.001 && bottom < 0)){ bottom = 0 }

        switch(position){
            case 0:
                let div = document.createElement("div")
                div.setAttribute("id", wheel_id + "_btn-" + i)
                div.setAttribute("class", "button btn-"+i+" hiddeable opacity2")
                div.style.left = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ right +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"
                div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ bottom +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"

                document.getElementById(wheel_id).append(div)
                document.getElementById(wheel_id + "_btn-" + i).innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#"+ btn_list[cont] +"'></use></svg>"
                cont++
            break;
            case 1:
                if(right >= 0 && bottom >= 0){
                    let div = document.createElement("div")
                    div.setAttribute("id", wheel_id + "_btn-" + i)
                    div.setAttribute("class", "button btn-"+i+" hiddeable opacity2")
                    div.style.left = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ right +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"
                    div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ bottom +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"

                    document.getElementById(wheel_id).append(div)
                    document.getElementById(wheel_id + "_btn-" + i).innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#"+ btn_list[cont] +"'></use></svg>"
                    cont++
                }
            break;
            case 2:
                if(right >= 0 && bottom <= 0){
                    let div = document.createElement("div")
                    div.setAttribute("id", wheel_id + "_btn-" + i)
                    div.setAttribute("class", "button btn-"+i+" hiddeable opacity2")
                    div.style.left = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ right +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"
                    div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ bottom +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"

                    document.getElementById(wheel_id).append(div)
                    document.getElementById(wheel_id + "_btn-" + i).innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#"+ btn_list[cont] +"'></use></svg>"
                    cont++
                }
            break;
            case 3:
                if(right <= 0 && bottom <= 0){
                    let div = document.createElement("div")
                    div.setAttribute("id", wheel_id + "_btn-" + i)
                    div.setAttribute("class", "button btn-"+i+" hiddeable opacity2")
                    div.style.left = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ right +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"
                    div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ bottom +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"

                    document.getElementById(wheel_id).append(div)
                    document.getElementById(wheel_id + "_btn-" + i).innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#"+ btn_list[cont] +"'></use></svg>"
                    cont++
                }
            break;
            case 4:
                if(right <= 0 && bottom >= 0){
                    let div = document.createElement("div")
                    div.setAttribute("id", wheel_id + "_btn-" + i)
                    div.setAttribute("class", "button btn-"+i+" hiddeable opacity2")
                    div.style.left = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ right +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"
                    div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2)) + calc("+ bottom +" * calc(calc(var(--wheel-size) - var(--button-width)) / 2)))"

                    document.getElementById(wheel_id).append(div)
                    document.getElementById(wheel_id + "_btn-" + i).innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#"+ btn_list[cont] +"'></use></svg>"
                    cont++
                }
            break;
        }
    }

    let div = document.createElement("div")
    div.setAttribute("id", wheel_id + "_btn-center")
    div.setAttribute("class", "button btn-center")
    div.style.left = "calc(calc(50% - calc(var(--button-width) / 2))"
    div.style.bottom = "calc(calc(50% - calc(var(--button-width) / 2))"

    document.getElementById(wheel_id).append(div)
    document.getElementById(wheel_id + "_btn-center").innerHTML = "<svg fill='currentColor'><use href='icons/bootstrap-icons.svg#plus-circle-fill'></use></svg>"

    document.querySelectorAll("#"+wheel_id+" .btn-center")[0].addEventListener("click", function() {
        if (document.getElementById(wheel_id).classList.contains('spin')) {
            document.getElementById(wheel_id).classList.add('spin2');
            document.getElementById(wheel_id).classList.remove('spin');
            document.querySelectorAll("#"+wheel_id+" .hiddeable").forEach(button => {
                button.classList.add('opacity2');
                button.classList.remove('opacity');
            })
        }else{
            document.getElementById(wheel_id).classList.add('spin');
            document.getElementById(wheel_id).classList.remove('spin2');
            document.querySelectorAll("#"+wheel_id+" .hiddeable").forEach(button => {
                button.classList.add('opacity');
                button.classList.remove('opacity2');
            })
        }
    })
}

generate_buttons("button-wheel-c", 0, ['arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat'])
generate_buttons("button-wheel-tl", 2, ['arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat'])
generate_buttons("button-wheel-tr", 3, ['arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat'])
generate_buttons("button-wheel-bl", 1, ['arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat'])
generate_buttons("button-wheel-br", 4, ['arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat','arrow-repeat'])