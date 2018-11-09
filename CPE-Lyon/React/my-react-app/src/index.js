import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
//import App from './App';
import Main from './components/Main';
import * as serviceWorker from './serviceWorker';

const defaultTitle = "default_title"

//const mainComponent = <App title={defaultTitle}/>;
const mainComponent = <Main title={defaultTitle}/>;
ReactDOM.render(mainComponent, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
