import React from 'react';
import ReactDOM from 'react-dom';
import { createStore } from 'redux';
import { Provider } from 'react-redux';
import globalReducer from './reducers/index'
import './index.css';
import Main from './components/Main';
import * as serviceWorker from './serviceWorker';

const defaultTitle = "default_title"

//import App from './App';
//const mainComponent = <App title={defaultTitle}/>;

const store=createStore(globalReducer);
const mainComponent = (
    <Provider store={store}>
      <Main title={defaultTitle}/>
    </Provider>
);

ReactDOM.render(mainComponent, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
