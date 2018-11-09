import React, { Component } from 'react';

class Label extends Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <div>{this.props.label}</div>
    );
  }
}

export default Label;
