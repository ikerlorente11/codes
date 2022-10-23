function run(){
    let msg = new SpeechSynthesisUtterance();
    msg.text = "Bonito culito"
    msg.lang = 'es-Es'
    window.speechSynthesis.speak(msg);
}