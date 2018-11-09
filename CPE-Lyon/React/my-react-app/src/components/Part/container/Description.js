import React, { Component } from 'react';
import Price from "./Price";

class Description extends Component {
  render() {
    return(
      <div className="table">
        <div> ID : {this.props.part.id} </div>
        <div> NAME : {this.props.part.title} </div>
        <div>
          PRICE : <Price value={this.props.part.price} />
        </div>
      </div>
    );
  }
}

export default Description;
