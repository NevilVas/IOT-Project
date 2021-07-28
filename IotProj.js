/*window.setInterval('refresh()',1000);
function refresh(){
    window.location.reload();
}*/

// check app status
var request = new XMLHttpRequest();

request.open('GET', 'http://blynk-cloud.com/A4dvk3fk7M_hIVOuR0wSfpse2N9lYRkM/isAppConnected');

request.onreadystatechange = function () {
  if (this.readyState === 4) {
    console.log('Status:', this.status);
    console.log('Headers:', this.getAllResponseHeaders());
    document.getElementById("check").innerHTML = this.responseText;
  }
};

request.send();

// get values of water pump
var request = new XMLHttpRequest();

request.open('GET', 'http://blynk-cloud.com/A4dvk3fk7M_hIVOuR0wSfpse2N9lYRkM/get/V5');

request.onreadystatechange = function () {
  if (this.readyState === 4) {
      console.log('Status:', this.Status)
    document.getElementById("val").innerHTML = this.responseText;
  }
};

request.send();

//button on off
document.getElementById("b").onclick = buttonfun();
function buttonfun(){
  var request = new XMLHttpRequest();

request.open('PUT', 'http://blynk-cloud.com/A4dvk3fk7M_hIVOuR0wSfpse2N9lYRkM/update/V3');

request.setRequestHeader('Content-Type', 'application/json');

request.onreadystatechange = function () {
  if (this.readyState === 4) {
    console.log('Status:', this.status);
    console.log('Headers:', this.getAllResponseHeaders());
    console.log('Body:', this.responseText);
  }
};

var body = ['1'];

request.send(JSON.stringify(body));
    

}
