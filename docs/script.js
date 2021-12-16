document.getElementById('test').onclick = function () {
    document.getElementById('post').classList.add('button-clicked');
    document.getElementById('test').classList.add('link-clicked');
    document.getElementById('test').classList.remove('link-post');
    document.getElementById('courier').classList.remove('button-clicked');
    document.getElementById('test1').classList.remove('link-clicked');

}
document.getElementById('test1').onclick = function () {
    document.getElementById('courier').classList.add('button-clicked');
    document.getElementById('test1').classList.add('link-clicked');
    document.getElementById('test1').classList.remove('link-post');
    document.getElementById('post').classList.remove('button-clicked');
    document.getElementById('test').classList.remove('link-clicked');
}