const recognition = new webkitSpeechRecognition()
recognition.lang = 'es-ES'
recognition.continuous = true
recognition.onresult = event => {
	/*for(const result of event.results){
		console.log(result[0].transcript)
	}*/
	console.log(event.results[event.results.length - 1][0].transcript)
}
recognition.start()